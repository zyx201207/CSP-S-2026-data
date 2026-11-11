#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll inline ret() {
	ll t=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		t=t*10+ch-'0';
		ch=getchar();
	}
	return f*t;
}
ll C,n,m,D,Q;
ll w[500009];
struct node{
	ll to;
	ll use;
	node() {}
	node(ll t,ll u) {to=t;use=u;}
	bool operator < (const node & t) const {
		return use>t.use;
	}
};
vector<node>g[500509];
vector<ll>dis[500509];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=ret();m=ret();n=ret();D=ret();Q=ret();
	for(ll i=1;i<=n;i++){
		w[i]=ret();
	}
	for(ll i=1;i<=m;i++){
		ll L=ret();
		for(ll j=1;j<=L;j++){
			ll to=ret(),use=ret();
			g[to].push_back(node(i+n,use));
			g[i+n].push_back(node(to,use));
		}
	}
	for(ll i=1;i<=Q;i++){
		ll S=ret(),E=ret();
		if(dis[S].size()){
			printf("%lld\n",dis[S][E]+w[S]+w[E]);
			continue;
		}
		if(dis[E].size()){
			printf("%lld\n",dis[E][S]+w[S]+w[E]);
			continue;
		}
		dis[S].resize(n+m+10);
		for(ll go=1;go<n+m+10;go++){
			dis[S][go]=LLONG_MAX;
		}
		auto &ds=dis[S];
		ds[S]=0;
		priority_queue<node>q;
		q.push(node(S,0));
		while(q.size()){
			ll to=q.top().to;
			q.pop();
			for(node v:g[to]){
				ll too=v.to;
				ll usee=v.use;
				if(ds[too]>ds[to]+usee){
					ds[too]=ds[to]+usee;
					q.push(node(too,ds[too]));
				}
			}
		}
		printf("%lld\n",ds[E]+w[S]+w[E]);
	}
	return 0;
}
