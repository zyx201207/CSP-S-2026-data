#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5e5+10,NM=5e5+500+10;
ll c,n,m,d,q,w[M],f[NM];
vector<pair<ll,ll> >e[NM];
bitset<M>b;
set<pair<ll,ll> >s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		for(ll j=1,a,t;j<=k;j++){
			cin>>a>>t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		s.clear();
		for(ll i=1;i<=n+m;i++) f[i]=LLONG_MAX,s.insert({f[i],i});
		b.reset(),s.erase({f[x],x}),s.insert({0,x}),f[x]=0;
		while(!s.empty()){
			auto h=s.begin();
			ll u=(*h).second,len=e[u].size();
			if(u==y){
				cout<<w[x]+w[y]+f[y]<<'\n';
				break;
			}
			s.erase(h);
			for(ll i=0;i<len;i++){
				ll v=e[u][i].first,nw=e[u][i].second;
				if(!b[v]&&f[u]+nw<f[v]){
					s.erase({f[v],v});
					f[v]=f[u]+nw;
					s.insert({f[v],v});
				}
			}
		}
	}
	return 0;
}
