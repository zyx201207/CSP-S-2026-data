#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,d,q,d_k[500005],z[500005];
vector<vector<pair<ll,ll>>> v;
vector<vector<pair<ll,ll>>> h;
bool bo[500005];
ll bfs(ll x,ll y){
	for(int i=1;i<=m;i++) z[i]=LLONG_MAX;
	z[x]=0;
	memset(bo,0,sizeof(bo));
	ll o=0;
	o+=d_k[x]+d_k[y]; 
	queue<ll> ph;
	ph.push(x);
	while(!ph.empty()){
		ll w=ph.front();
		ph.pop();
		for(int i=0;i<h[w].size();i++){
			if(bo[h[w][i].first]) continue;
			bo[h[w][i].first]=1;
			ll as=h[w][i].first-1;
		    for(int j=0;j<v[as].size();j++){
		    	ll q=v[as][j].first;
		    	if(z[q]<=z[w]+v[as][h[w][i].second-1].second+v[as][j].second){
		    	    continue;
		        }
		    	z[q]=z[w]+v[as][h[w][i].second-1].second+v[as][j].second;
		    	ph.push(q);
		    	if(q==y) return o+z[y];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>d_k[i];
		h.push_back({});
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		vector<pair<ll,ll>> p;
		for(int j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			h[x].push_back({i,j});
			p.push_back({x,y});
		}
		v.push_back(p);
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<"\n";
	}
	return 0;
} 
