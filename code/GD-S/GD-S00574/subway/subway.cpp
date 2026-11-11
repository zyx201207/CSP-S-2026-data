#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PLI;
#define mkp make_pair
int c,n,m,d,q;
int w[500010],k[510];
ll dis[510][510];
vector<int> id[500010];
vector<PLI> G[510];
map<pair<int,int> ,ll> mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			int a;
			ll t;
			cin>>a>>t;
			id[a].push_back(i);
			mp[mkp(a,i)]=t;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i<=m;i++){
		for(auto u:id[i])
			for(auto v:id[i]){
				if(u==v) dis[u][v]=dis[v][u]=0;
				else dis[u][v]=min(mp[mkp(i,v)]+mp[mkp(i,u)],dis[u][v]);
			}
	}
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int l,r;
		cin>>l>>r;
		ll ans=1e18;
		for(auto u:id[l])
			for(auto v:id[r]) ans=min(ans,dis[u][v]+mp[mkp(l,u)]+mp[mkp(r,v)]);
		cout<<ans+w[l]+w[r]<<"\n";
	}
	return 0;
}
