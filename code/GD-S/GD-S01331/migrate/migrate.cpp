#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c,t;
int n;
ll d;
ll num[2000002];

ll anss[2000002][2];
int ans;

int main()
{
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t --)
	{
		ans = 0;
		scanf("%d%lld",&n,&d);
		for (int i = 1;i <= n;i ++) scanf("%lld",&num[i]);
		
		for (int i = 1;i <= n;i ++)
		{
			for (int f = i + 1;f <= n;f ++) 
			{
				anss[f][0] = 1e18;
				anss[f][1] = 0;
			}
			anss[i][0] = 0;
			anss[i][1] = 0;
			for (int f = i;f <= n;f ++)
			{
				for (int ts = f + 1;ts <= n;ts ++)
				{
					if (num[f] + d >= num[ts] || ts == f + 1)
					{
						if (anss[ts][0] > anss[f][0] + 1)
						{
							anss[ts][0] = anss[f][0] + 1;
							anss[ts][1] = 1;
						}else if (anss[ts][0] == anss[f][0] + 1) 	
							anss[ts][1] ++;
					}else break;
				}
				if (anss[f][1] == 2) ans ++;
			}
		}
			
		printf("%d\n",ans);
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

0 1
8 3
0 1 2 4 8 10 11 13
*/

