#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const ll gun_mu=67676767;
ll dis_xian[509][509];
ll out[1145141];
vector<pair<ll,ll>> lu[1145141];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ll c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>out[i];
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++) dis_xian[i][j]=114514191981000;
	for(ll i=1;i<=n;i++)
	{
		ll k;cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll v,w;cin>>v>>w;
			lu[v].push_back({i,w});
		}
	}
	for(ll i=1;i<=m;i++)
		for(ll j=0;j<lu[i].size();j++)
			for(ll k=j+1;k<lu[i].size();k++)
			{
				ll v1=lu[i][j].first,w1=lu[i][j].second;
				ll v2=lu[i][k].first,w2=lu[i][k].second;
				dis_xian[v1][v2]=min(dis_xian[v1][v2],w1+w2);
				dis_xian[v2][v1]=min(dis_xian[v2][v1],w1+w2);
			}
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				dis_xian[i][j]=min(dis_xian[i][j],dis_xian[i][k]+dis_xian[k][j]);
	while(q--)
	{
		ll u,v;cin>>u>>v;
		ll ans=114514191981000;
		for(int i=0;i<lu[u].size();i++)
			for(int j=0;j<lu[v].size();j++)
			{
				ll v1=lu[u][i].first,w1=lu[u][i].second;
				ll v2=lu[v][j].first,w2=lu[v][j].second;
				if(v1==v2) ans=min(ans,w1+w2+out[u]+out[v]);
				else ans=min(ans,w1+w2+dis_xian[v1][v2]+out[u]+out[v]);
			}
		cout<<ans<<endl;
	}
} 
