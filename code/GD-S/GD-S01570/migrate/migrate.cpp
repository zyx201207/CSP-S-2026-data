#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
int x[2200000];
int sum[5500][5500];
int mn[5500][5500];
void dfs(int now,int s,int e,int len)
{
	if (len>mn[s][e])
		return;
	if (now==e)
	{
		if (len==mn[s][e])
			sum[s][e]++;
		else
		{
			mn[s][e]=len;
			sum[s][e]=1;
		}
	}
	for (int i=now+1;i<=e;i++)
		if (x[i]-x[now]<=d)
		{
			dfs(i,s,e,len+1);
		}
		else
		{
			break;
		}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while (T--)
	{
		memset(sum,0,sizeof(sum));
		int ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>x[i];
		for (int i=1;i<n;i++)
		{
			for (int j=i+3;j<=n;j++)
			{
				mn[i][j]=2e18;
				dfs(i,i,j,0);
				if (sum[i][j]==2)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
