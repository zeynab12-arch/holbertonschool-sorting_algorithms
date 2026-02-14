#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr)
	{
		next = curr->next;
		prev = curr->prev;

		while (prev && curr->n < prev->n)
		{
			/* Fix next of prev */
			prev->next = curr->next;
			if (curr->next)
				curr->next->prev = prev;

			/* Move curr before prev */
			curr->prev = prev->prev;
			curr->next = prev;

			if (prev->prev)
				prev->prev->next = curr;
			else
				*list = curr;

			prev->prev = curr;

			print_list(*list);

			prev = curr->prev;
		}
		curr = next;
	}
}
