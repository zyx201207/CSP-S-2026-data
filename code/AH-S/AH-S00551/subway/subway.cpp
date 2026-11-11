#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M=5e5+5,N=505;
struct node{
	LL pos,t;
	bool operator<(const node &p)const{
		return t>p.t;
	}
};
LL c,n,m,d,T;
LL a[M],disG[N][N],op[N],dis[N];
vector<node> b[M],tr[N],G[N];
priority_queue<node> q;
void dij(LL s){
	while(!q.empty()){
		q.pop();
	}
	fill(dis+1,dis+n+1,-1);
	dis[s]=0;q.push((node){s,0});
	while(!q.empty()){
		node u=q.top();q.pop();
		if(u.t>dis[u.pos]){
			continue;
		}
		for(auto i:G[u.pos]){
			LL v=i.pos,w=i.t;
			if((dis[v]==-1)||(dis[v]>dis[u.pos]+w)){
				dis[v]=dis[u.pos]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
	for(LL i=1;i<=n;i++){
		disG[s][i]=dis[i];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&T);
	for(LL i=1;i<=m;i++){
		scanf("%lld",a+i);
	}
	for(LL i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(LL j=1,x,y;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			tr[i].push_back((node){x,y});
			b[x].push_back((node){i,y});
		}
	}
	for(LL i=1;i<=n;i++){
		fill(op+1,op+n+1,-1);
		op[i]=0;
		for(auto u:tr[i]){
			for(auto v:b[u.pos]){
				if(v.pos!=i){
					if(op[v.pos]==-1){
						op[v.pos]=u.t+v.t;
					}else{
						op[v.pos]=min(op[v.pos],u.t+v.t);
					}
				}
			}
		}
		for(LL j=1;j<=n;j++){
			if((j!=i)&&op[j]!=-1){
				G[i].push_back((node){j,op[j]});
			}
		}
	}
	for(LL i=1;i<=n;i++){
		dij(i);
	}
	while(T--){
		LL st,ed;
		scanf("%lld%lld",&st,&ed);
		LL ans=-1;
		for(auto u:b[st]){
			for(auto v:b[ed]){
				if(ans==-1){
					ans=disG[u.pos][v.pos]+u.t+v.t;
				}else{
					ans=min(ans,disG[u.pos][v.pos]+u.t+v.t);
				}
			}
		}
		printf("%lld\n",ans+a[st]+a[ed]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
