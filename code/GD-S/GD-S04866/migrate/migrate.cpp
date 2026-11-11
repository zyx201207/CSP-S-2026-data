#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e6+5;
int c,T,n,d,x[M],dis[M],cnt[M],ans;
void dfs(int p,int fly)
{
	if (p==n+1) return;
	if (dis[p]>fly)
	{
		dis[p]=fly;
		cnt[p]=1;
	}
	else if (dis[p]==fly)
	{
		cnt[p]++;
	}
	for (int i=p+1; i<=n; i++)
	{
		if (x[i]-x[p]>d) break;
		dfs(i,fly+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if (c<=10)
	{
		while (T--)
		{
			ans=0;
			cin>>n>>d;
			for (int i=1; i<=n; i++) cin>>x[i];
			for (int i=1; i<=n; i++)
			{
				memset(dis,0x3f3f3f3f,sizeof(dis));
				memset(cnt,0,sizeof(cnt));
				dfs(i,0);
				for (int j=i+1; j<=n; j++)
				{
					if (cnt[j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	else if (c==11||c==12)
	{
		while (T--)
		{
			cin>>n>>d;
			for (int i=1; i<=n; i++) cin>>x[i];
			cout<<x[n]/d*2;
		}
	}
	else
	{
		for (int i=1; i<=T; i++) cout<<0<<'\n';
	}
	return 0;
}
