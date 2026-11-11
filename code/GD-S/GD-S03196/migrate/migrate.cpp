#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
ll a[N];
int c,T,n,left[N],right[N],g[305][305][305];
ll d,ans;
int st;
void dfs(int x,int sum)
{
	g[st][x][sum]++;
	for(int i=x+1;i<=n;i++)
	{
		if(a[i] - a[x] <= d)
		{
			dfs(i,sum+1);
		}
		else return;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		memset(g,0,sizeof(g));
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			st = i;
			dfs(i,0);
		}
		ans = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(g[i][j][k])
					{
						if(g[i][j][k] == 2)
						{
							ans++;
						}
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
