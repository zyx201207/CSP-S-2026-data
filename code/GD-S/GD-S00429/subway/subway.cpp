#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
struct node{
	int k;
	vector<int> s,t;
//	int s,t;
}a[505];
struct node2{
	int v,w;
};
struct node3{
	int lid,th;
};
struct node4{
	int id,val;
};
int c,n,m,d,Q;
bool operator <(const node4 &o,const node4 &p){
	return o.val>p.val;
}
int dis[2005];
int G2[505][505];
vector<node2> G[500005];
vector<node3> lines[500005];
void bfs(int x){
	memset(dis,0x3f,sizeof(dis));
//	for(int i=1; i<=m; i++) dis[i]=0x3f3f3f3f3f3f3f3f;
	priority_queue<node4> q;
	q.push({x,0});
	dis[x]=0;
	while(q.size()){
		int now=q.top().id,V=q.top().val;
		q.pop();
		if(dis[now]<V) continue;
		for(int i=0; i<(int)G[now].size(); i++){
			int tx=G[now][i].v,ty=G[now][i].w;
			if(dis[tx]>dis[now]+ty){
				dis[tx]=dis[now]+ty;
				q.push({tx,dis[tx]});
			}
		}
	}
}
//vector<int> id[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	int c,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
	for(int i=1; i<=m; i++) scanf("%lld",&w[i]);
	int F=0;
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i].k);
		a[i].s.push_back(0);
		a[i].t.push_back(0);
		for(int j=1; j<=a[i].k; j++){
			int S,T;
			scanf("%lld %lld",&S,&T);
			F=T;
			a[i].s.push_back(S);
			a[i].t.push_back(T);
			lines[S].push_back({i,j});//几号线 
//			id[i][S]=T;//i号线车站 S 时间 T  
		}
	}
	if(c<=19&&c>=12){
		memset(G2,0x3f,sizeof(G2));
		for(int i=1; i<=m; i++){
			for(int j=0; j<(int)lines[i].size(); j++){
				for(int k=j+1; k<(int)lines[i].size(); k++){
					G2[lines[i][j].lid][lines[i][k].lid]=1;
					G2[lines[i][k].lid][lines[i][j].lid]=1;
				}
			}
		}	
		for(int i=1; i<=n; i++) G2[i][i]=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int k=1; k<=n; k++){
					G2[j][k]=min(G2[j][i]+G2[i][k],G2[j][k]);
				}
			}
		}
		while(Q--){
			int x,y;
			scanf("%lld %lld",&x,&y);
			int mi=LLONG_MAX;
			for(int i=0; i<(int)lines[x].size(); i++){
				for(int j=0; j<(int)lines[y].size(); j++){
					mi=min(mi,G2[lines[x][i].lid][lines[y][j].lid]);
				}
			}
			printf("%lld\n",(mi+1)*2*F+w[x]+w[y]);
		}
		return 0;
	}
	for(int i=1; i<=m; i++){
		for(int j=0; j<(int)lines[i].size(); j++){
			for(int K=1; K<=a[lines[i][j].lid].k; K++){
				G[i].push_back({a[lines[i][j].lid].s[K],a[lines[i][j].lid].t[K]+a[lines[i][j].lid].t[lines[i][j].th]});
				G[a[lines[i][j].lid].s[K]].push_back({i,a[lines[i][j].lid].t[K]+a[lines[i][j].lid].t[lines[i][j].th]});
//				printf("%lld %lld %lld\n",i,a[lines[i][j].lid].s[K],a[lines[i][j].lid].t[K]+a[lines[i][j].lid].t[lines[i][j].th]);
			}
		}
	}
	while(Q--){
		int x,y;
		scanf("%lld %lld",&x,&y);
		bfs(x);
//		for(int i=1; i<=m; i++) printf("%lld ",dis[i]);
		printf("%lld\n",dis[y]+w[x]+w[y]);
	}
	return 0;
}
