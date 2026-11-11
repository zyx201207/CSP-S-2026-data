#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,e,Q,w[500005],d[505][505];
struct hi{ll a,t;};
vector<hi> mp[500505];
int main()
{
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>e>>Q;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) d[i][j]=1e18;
		d[i][i]=0;
	}
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1,k,a,t,l;i<=n;i++)
	{
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			cin>>a>>t;
			l=mp[a].size();
			for(ll o=0;o<l;o++)
			{
				d[i][mp[a][o].a]=min(d[i][mp[a][o].a],mp[a][o].t+t);
				d[mp[a][o].a][i]=min(d[mp[a][o].a][i],mp[a][o].t+t);
			}
			mp[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll k=1;k<=n;k++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	while(Q--)
	{
		ll u,v,ans=1e18,l1,l2;
		cin>>u>>v;
		l1=mp[u].size();
		l2=mp[v].size();
		for(ll i=0;i<l1;i++)
		{
			for(ll j=0;j<l2;j++) ans=min(ans,d[mp[u][i].a][mp[v][j].a]+mp[u][i].t+mp[v][j].t);
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	return 0;
}