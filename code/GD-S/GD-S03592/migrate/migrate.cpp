#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
long long T,n,d,x[2000500],sh[15][15][15],ans,ifa,acnt,sm;
void dfs(long long r,long long xx,long long step)
{
	for(int i = xx+1;i <= n;i++)
	{
		if(x[i]-x[xx] <= d)
		{
			sh[r][i][step+1]++;
			dfs(r,i,step+1);
		}else break;
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> T >> T;
	while(T--)
	{
		ans = 0;
		memset(sh,0,sizeof(sh));
		scanf("%lld%lld",&n,&d);
		ifa = 1;
		sm += n;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld",&x[i]);
		}
		for(int i = 3;i <= n;i++)
		{
			if(x[i]-x[i-1] != x[i-1]-x[i-2])
			{
				ifa = 0;
				break;
			}
		}
		if(ifa)
		{
			sm = 0;
			for(int i = 2;i <= n;i++)
			{
				if(x[1]+d < x[i])
				{
					acnt = i-2;
					break;
				}
				if(i == n)
				{
					acnt = n-1;
				}
			}
			//cout << acnt << " ";
			if(acnt <= 1) printf("0\n");
			else printf("%lld\n",max(n-acnt*2+1,0ll));
			continue; 
		}
		else if(sm <= 10)
		{
			for(int i = 1;i <= n;i++)
			{
				dfs(i,i,0);
			}
			for(int i = 1;i <= n;i++)
			{
				for(int j = i+1;j <= n;j++)
				{
					for(int k = 1;k <= n;k++)
					{
						if(sh[i][j][k] != 0)
						{
							if(sh[i][j][k] == 2) ans++;
							break;
						}
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
}
