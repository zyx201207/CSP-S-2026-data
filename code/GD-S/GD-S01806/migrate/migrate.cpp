#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,ans,a[2000100],dp[5010][5010],f[5010][5010];
void dfs(int x,int y,int p)
{
	if(y==dp[p][x])
	{
		f[p][x]++;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]-a[x]>d)
		{
			break;
		}
		dfs(i,y+1,p);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		memset(dp,0x3f,sizeof(dp));
		memset(f,0,sizeof(f));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][i]=0;
			int num=1,las=i;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[las]<=d)
				{
					dp[i][j]=num;
				}
				else
				{
					las=j-1;
					if(a[j]-a[las]<=d)
					{
						num++;
						dp[i][j]=num;
					}
					else
					{
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dfs(i,0,i);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(f[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 
-999999999999999993 -999999999999999992 -999999999999999991 
-999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
1:2
2:3
3:4 5 6
4:5 6 7
5:6 7 8
6:7 8
7:8
8:9
9:10
*/
