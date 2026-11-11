#include<bits/stdc++.h>
#define ll long long
#define For(i, x, y) for(int i = x; i <= y; i++)
#define RFor(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
const int N = 5e5+5, M = 3e5+5;
int n, m;
int a[N];
int tmp_las[N], nxt[N];
int find(int x)
{
//	printf("%d %d\n",x, nxt[x]);
	if(!nxt[x]) return x;
	return nxt[x] = find(nxt[x]);
}
int ans[M];
int main()
{
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
	scanf("%d%d",&n, &m);
	For(i, 1, n)
	{
		scanf("%d",&a[i]);
		nxt[tmp_las[a[i]]] = i;
		tmp_las[a[i]] = i;
	}
	nxt[0] = 0;
//	For(i, 0, n)
//		printf("nxt[%d] = %d\n",i,  nxt[i]);
	For(l, 1, n)
	{
		For(i, l, n)
		{
			if(find(nxt[i]))
			{
				i = nxt[i]-1;
				continue;
			}
//			printf("%d ",a[i]);
			ans[a[i]]++;
		}
//		printf("\n");
	}
	
	For(i, 1, m)
		printf("%d ",ans[i]);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
// card.out card.ans
