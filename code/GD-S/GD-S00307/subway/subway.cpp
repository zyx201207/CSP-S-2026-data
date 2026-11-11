#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
using namespace std;
const ll N=500505,inf=0x3f3f3f3f3f3f3f3f;
ll kd(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll anaxa,n,m,dd,q,ww[N],hd[N],nxt[N<<1],to[N<<1],w[N<<1],t,d[N],st,ed;
void jia(ll u,ll v,ll wi){
	to[++t]=v;
	w[t]=wi;
	nxt[t]=hd[u];
	hd[u]=t;
}
void dij(){
	priority_queue<pi,vector<pi >,greater<pi > > q;
	q.push({0,st});
	memset(d,inf,sizeof d);
	bool vis[N]={0};
	d[st]=0;
	while(!q.empty()){
		ll u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(ll i=hd[u];i;i=nxt[i]){
			ll v=to[i];
			if(d[v]>d[u]+w[i]){
				d[v]=d[u]+w[i];
				if(v==ed) return;
				q.push({d[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>anaxa>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) ww[i]=kd();
	for(ll i=1,k,wi,v;i<=n;i++){
		scanf("%lld",&k);
		while(k--){
			scanf("%lld%lld",&v,&wi);
			jia(500000+i,v,wi);
			jia(v,i+500000,wi);
		}
	}
	while(q--){
		st=kd();ed=kd();
		dij();
		printf("%lld\n",ww[st]+ww[ed]+d[ed]);
	}
} 
