#include <iostream>
using namespace std;

const int N = 5e5 + 10;

int q[N], ans[N], d[N], id[N], desk[N], n, m, cnt;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", d + i);
	}
//	if (n <= 500)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			cnt = 0;
//			for (int j = i; j <= n; j++)
//			{
//				if (id[d[j]])
//				{
//					for (; cnt > id[d[j]]; cnt--)
//					{
//						id[d[desk[cnt]]] = 0;
//					}
//				}
//				else
//				{
//					id[d[j]] = ++cnt;
//					desk[cnt] = j;
//				}
//			}
//			for (; cnt > 0; cnt--)
//			{
//				ans[d[desk[cnt]]]++;
//				printf("%d ", desk[cnt]);
//			}
//			printf("\n");
//		}
//		for (int i = 1; i <= m; i++)
//		{
//			printf("%d ", ans[i]);
//		}
//		return 0;
//	}
	for (int i = n; i >= 1; i--)
	{
		if (id[d[i]])
		{
			for (; cnt > id[d[i]]; cnt--)
			{
				ans[d[desk[cnt]]] += (q[d[desk[cnt]]] - i);
				q[d[desk[cnt]]] = 0;
				id[d[desk[cnt]]] = 0;
			}
		}
		else
		{
			id[d[i]] = ++cnt;
			desk[cnt] = i;
			q[d[i]] = i;
		}
	}
	for (; cnt > 0; cnt--)
	{
		ans[d[desk[cnt]]] += q[d[desk[cnt]]];
		q[d[desk[cnt]]] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		printf("%d ", ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
