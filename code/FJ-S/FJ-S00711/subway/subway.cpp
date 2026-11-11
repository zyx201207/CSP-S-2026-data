#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=5e5+10;
ll c,n,m,p,q;
ll start[N],a[N],t[N];
ll e[N],ne[N],h[N],idx;
ll w[N],d[N];
bool st[N];
void add(ll a,ll b,ll c){
	w[idx]=c;
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
ll dj(ll s){
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	priority_queue<pll,vector<pll>,greater<pll> > heap;
	heap.push({0,s});
	while(!heap.empty()){
		pll k=heap.top();
		heap.pop();
		ll dis=k.first,ver=k.second;
		if(st[ver]) continue;
		st[ver];
		for(ll i=h[ver];i!=-1;i=ne[i]){
			ll j=e[i];
			if(d[j]>dis+w[i]){
				d[j]=dis+w[i];
				heap.push({d[j],j});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(h,-1,sizeof(h));
	cin>>c>>n>>m>>p>>q;
	for(ll i=1;i<=m;i++){
		cin>>start[i];
	}
	while(n--){
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		ll k;
		cin>>k;
		for(ll i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
		for(ll i=1;i<=k;i++){
			for(ll j=i+1;j<=k;j++){
				add(a[i],a[j],t[i]+t[j]);
			}
		}
	}
	while(q--){
		ll l,r;
		cin>>l>>r;
		dj(l);
		cout<<start[l]+start[r]+d[r]<<endl;
	}
	return 0;
}
