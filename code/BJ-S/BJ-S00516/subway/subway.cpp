#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int min(int x,int y)
{
	return x<y?x:y;
}
//纪念1217king被M28封号默哀.....
int w[500001],vis[501][501],sub[500001][21],t[500001][21],cnt[500001];
signed main()
{
	ios::sync_with_stdio(0);
	for(int i=1;i<=500;++i)
	{
		for(int j=1;j<=500;++j)
		{
			if(i==j)
			{
				continue;
			}
			vis[i][j]=1e18;
		}
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,ti;
			cin>>x>>ti;
			cnt[x]++;
			sub[x][cnt[x]]=i;
			t[x][cnt[x]]=ti;
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=cnt[i];++j)
		{
			for(int k=1;k<=cnt[i];++k)
			{
				vis[sub[i][j]][sub[i][k]]=min(vis[sub[i][j]][sub[i][k]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				vis[i][j]=min(vis[i][j],vis[i][k]+vis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];++i)
		{
			for(int j=1;j<=cnt[y];++j)
			{
				ans=min(ans,w[x]+w[y]+t[x][i]+t[y][j]+vis[sub[x][i]][sub[y][j]]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}