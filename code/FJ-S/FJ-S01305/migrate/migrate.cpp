#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int M=1e9+5;
long long c,T,n,m,minn,a[N];
bool vis[M];
int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		int ans=0;
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		minn=1e18+5;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			minn=min(minn,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			vis[a[i]-minn]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]+2*m-1-minn]&&(vis[a[i]+m-minn]||vis[a[i]+m-1-minn]))
			{
				ans++;
			}
		}
		cout<<ans<<'\n';
	}





	return 0;
}

