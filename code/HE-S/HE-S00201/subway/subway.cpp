#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[500005],f[505][505],inf;
vector<pair<int,ll>>a[500005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	memset(f,0x3f,sizeof f);
	inf=f[0][0];
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
		int aa;
		cin>>aa;
		while(aa--)
		{
			int x;
			ll t;
			cin>>x>>t;
			a[x].emplace_back(i,t);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto j:a[i])
		{
			for(auto k:a[i])
			{
				if(j.first==k.first)continue;
				f[j.first][k.first]=f[k.first][j.first]=min(f[j.first][k.first],j.second+k.second);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		ll ans=inf;
		cin>>x>>y;
		for(auto i:a[x])
		{
			for(auto j:a[y])
			{
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+v[x]+v[y]<<'\n';
	}
	return 0;
}
