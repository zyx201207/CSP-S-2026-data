#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+5;
struct node{ll id,val;};
vector <node> scc[500005];
ll c,n,m,d,q;
ll W[500005],e[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>W[i];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			e[i][j]=2e18;
		}
		e[i][i]=0;
	}
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll a,t;
			cin>>a>>t;
			for(auto ed : scc[a])
			{
				ll id=ed.id,val=ed.val;
				e[i][id]=e[id][i]=min(e[i][id],val+t);
			}
			scc[a].push_back({i,t});
		}
	}
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll k=1;k<=n;k++)
			{
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	
	while(q--)
	{
		ll u,v,ans=2e18;
		cin>>u>>v;
		for(auto xu:scc[u])
		{
			for(auto xv:scc[v])
			{
				ll sum=0;
				sum+=xu.val+xv.val;
				sum+=e[xu.id][xv.id];
				sum+=W[u]+W[v];
				ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
