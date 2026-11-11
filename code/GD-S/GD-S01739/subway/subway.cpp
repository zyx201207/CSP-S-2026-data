#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
const ll MX=1e18+1;
ll w[N],dis[N+900];
bool f[N+900];
ll c,n,m,d,q;
struct dada{
	ll w,q;
};
vector<dada>v[N+600];
ll dij(ll str,ll end){
	//printf("str=%lld end=%lld\n",str,end);
	ll ans=w[str]+w[end];
	priority_queue<pair<ll,ll>>qu;
	qu.push({0,str});
	f[str]=1;
	while(qu.size()){
		auto tp=qu.top();
		ll tpq=tp.second,tpw=-tp.first;
		//printf("tpq=%lld tpw=%lld\n",tpq,tpw);
		qu.pop();
		for(auto i:v[tpq]){
			//printf("	1tpq=%lld i.q=%lld sum=%lld dis=%lld\n",tpq,i.q,i.w+tpw,dis[i.q]);
			if(f[i.q])continue;
			
			if(dis[i.q]>=tpw+i.w){
				dis[i.q]=tpw+i.w;
				f[i.q]=1;
				qu.push({-dis[i.q],i.q});
			}
			//printf("	2tpq=%lld i.q=%lld sum=%lld dis=%lld\n",tpq,i.q,i.w+tpw,dis[i.q]);
		}
	}return ans+dis[end];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll t=1;
	//scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
		for(int i=1;i<=m;i++){
			scanf("%lld",&w[i]);
		}
		for(int i=1;i<=n;i++){
			ll k,a,t;
			scanf("%lld",&k);
			for(int j=1;j<=k;j++){
				scanf("%lld%lld",&a,&t);
				v[a].push_back({t,N+i});
				v[N+i].push_back({t,a});
			}
		}
		while(q--){
			ll o,g;
			for(int i=0;i<=m;i++){
				dis[i]=MX,f[i]=0;
			}for(int i=N;i<=N+n;i++){
				dis[i]=MX,f[i]=0;
			}
			scanf("%lld%lld",&o,&g);
			//printf("xy %lld %lld\n",MX,g);
			printf("%lld\n",dij(o,g));
		}
	}
	return 0;
}
