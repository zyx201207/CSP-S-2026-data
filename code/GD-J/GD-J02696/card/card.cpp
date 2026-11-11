#include <bits/stdc++.h>
using namespace std;

struct nde{
	int p = 0;
	bool fl = 0;
};

int n, m, a[500005], ans[500005];
bool fl = 1;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] < a[i - 1]){
			fl = 0;
			//~ cout << "no" << endl;
		}
	}
	if(fl)
	{
		//~ cout << 1 << endl;
		int u = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != a[i - 1] && u)
			{
				printf("%d ", u);
			}
			u++;
		}
		if(u)
		{
			printf("%d", u);
		}
		printf("\n");
	}
	else
	{
		for(int st = 1; st <= n; st++)
		{
			nde vis[500005];
			for(int i = st; i <= n; i++)
			{
				if(vis[a[i]].fl == 1)
				{
					for(int k = vis[a[i]].p; k < i; k++)
					{
						vis[a[k]].fl = 0;
					}
					vis[a[i]].p = i;
				}
				else
				{
					vis[a[i]].fl = 1;
				}
			}
			for(int i = 1; i <= m; i++)
			{
				ans[i] += vis[i].fl;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}


