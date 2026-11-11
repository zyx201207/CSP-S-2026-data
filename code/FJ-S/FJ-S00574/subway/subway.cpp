#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,ma[500005],minn=INT_MAX;
map<ll,vector<ll> > na,zou;
map<ll,ll> nat;
queue<ll> qu;
void bfs(ll l,ll r,ll sum){
	if(l==r){
		minn=min(minn,sum);
		return;
	}
	ll oi=qu.front();
	qu.pop();
	sum+=nat[l];
	for(auto w:na[l]){
		bool ok=0;
		for(auto q:zou[l]) if(q==w) ok==1;
		if(!ok){
			qu.push(w);
		}
	}
	zou[l].push_back(oi);
	zou[oi].push_back(l);
	bfs(oi,r,sum+=nat[oi]);
	zou[l].pop_back();
	zou[oi].pop_back();
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>ma[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		vector<ll> ai;
		ai.clear();
		for(ll j=1;j<=k;j++){
			ll aai,ti;
			cin>>aai>>ti;
			ai.push_back(aai);
			nat[aai]=ti;
		}
		for(auto j:ai){
			for(auto w:ai){
				if(j==w) continue;
				na[j].push_back(w);
			}
		}
	}
	while(q--){
		ll x,y;
		minn=INT_MAX;
		while(!qu.empty()) qu.pop();
		cin>>x>>y;
		bfs(x,y,0);
		ll ans=ma[x]+ma[y]+minn;
		cout<<ans<<"\n";
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
