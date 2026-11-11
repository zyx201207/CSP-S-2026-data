#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500005;
ll c,n,m,d,q,W[N],a[500005],t,k[505],x,y,dd[500005];
struct node{
	ll v,w;
};
vector<node> e[N];
void add(ll u,ll v,ll w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>W[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[j]>>t;
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>x>>y;
		cout<<W[x]+W[y]<<"\n";
	}
	return 0;
}
