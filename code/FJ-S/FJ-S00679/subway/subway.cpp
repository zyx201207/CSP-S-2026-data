#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=500005,INF=1e9;
int c,n,m,d,Q,cnt;
int w[N];
int hd[N],to[M],nxt[M],ve[M];
long long dis[N];
bool vis[N];

priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
inline int rp(int stat,int p){
	return p+stat*m;
}
void add(int u,int v,int z){
	to[++cnt]=v;
	nxt[cnt]=hd[u];
	ve[cnt]=z;
	hd[u]=cnt;
}
void dij(int s){
	q.push(make_pair(0,s));
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]) continue;
			//cout<<u<<"->"<<v<<"\n";
			if(dis[v]>dis[u]+ve[i]){
				//cout<<v<<":"<<dis[v]<<"->"<<dis[u]+ve[i]<<"="<<u<<":"<<dis[u]<<"+"<<ve[i]<<"\n";
				dis[v]=dis[u]+ve[i];
				q.push(make_pair(dis[v],v));
			}
		}
		//cout<<"\n";
	}
}
void init(){
	for(int i=0;i<=N-1;i++){
		dis[i]=INF;
		vis[i]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k,a,t,pre=-1;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			if(pre!=-1){
				add(rp(i,pre),rp(i,a),0);
			}
			pre=a;
			add(rp(i,a),a,t);
			add(a,rp(i,a),t);
		}
	}
	while(Q--){
		init();
		int xx,yy;
		long long ans=-114514;
		scanf("%d%d",&xx,&yy);
		dij(xx);
		ans=dis[yy];
		if(ans==1e9)ans=300;
		printf("%lld\n",w[xx]+w[yy]+ans);
	}
	return 0;
}//676767meitiaochulai fk
