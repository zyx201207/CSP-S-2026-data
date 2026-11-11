#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Edge{
	ll next,to,v;
}edge[2000010];
	ll head[501000],cnt=0;
void add(ll from,ll to,ll v){
	cnt++;
	edge[cnt].to=to;
	edge[cnt].v=v;
	edge[cnt].next=head[from];
	head[from]=cnt;
	return;
}
struct wa{
	ll pos,dis;
	ll operator <(const wa &x)const{
		return x.dis<dis;
	}
};
	priority_queue <wa> q;
	ll dis[501000];
	ll vis[501000];
	ll get_out[500];
	ll c,n,m,d,r;
ll dijkstra(ll s,ll t){
	for(ll i=1;i<=m+n;i++)vis[i]=0;
	for(ll i=1;i<=m+n;i++)dis[i]=0x3f3f3f3f3f3fLL;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		ll p=q.top().pos;
		q.pop();
		if(vis[p]==1)continue;
		vis[p]=1;
		for(ll i=head[p];i;i=edge[i].next){
			ll x=edge[i].to;
			if(dis[x]>dis[p]+edge[i].v){
				dis[x]=dis[p]+edge[i].v;
				if(vis[x]==0){
					q.push({x,dis[x]});
				}
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>r;
	for(ll i=1;i<=m;i++)cin>>get_out[i];
	for(ll i=1;i<=n;i++){
		ll k,x=m+i;
		cin>>k;
		for(ll j=1,y,v;j<=k;j++){
			cin>>y>>v;
			add(x,y,v);
			add(y,x,v);
		}
	}
//	for(ll i=1;i<=n+m;i++){
//		cout<<i<<": ";
//		for(ll j=head[i];j;j=edge[j].next)cout<<edge[j].to<<" "<<edge[j].v<<" ";
//		cout<<"\n";
//	}
	
	while(r--){
		ll s,t;
		cin>>s>>t;
		cout<<dijkstra(s,t)+get_out[s]+get_out[t]<<"\n";
	}
	return 0;
}
//T2
//csp-s 2026 RP++
