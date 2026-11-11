#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n=205,max_m=405,max_k=405,INF=0x3f3f3f3f3f3f3f3f;
struct Edge{
	int u,v,w,nxt;
}e[max_m*max_m];
int h[max_m],idx;
void add(int u,int v,int w){
	e[++idx]={u,v,w,h[u]};
	h[u]=idx;
}
int c,n,m,d,Q;
int st[max_n];
int w[max_m],a[max_k],t[max_k],k[max_n];
int dist[max_m][max_m],vs[max_m][max_m];
int r[max_m][max_m];
priority_queue<pair<int,int> > q;
void dj(){
	for(int T=1;T<=m;T++){
		dist[T][T]=0;
		q.push({0,T});
		while(!q.empty()){
			pair<int,int> pr=q.top();
			q.pop();
			int f=pr.second;
			if(vs[T][f]){
				continue;
			}
			vs[T][f]=1;
			for(int i=h[f];i;i=e[i].nxt){
				int v=e[i].v;
				if(dist[T][v]>dist[T][f]+e[i].w){
					dist[T][v]=dist[T][f]+e[i].w;
					if(!vs[T][v]){
						q.push({-dist[T][v],v});
					}
				}
			}
		}
	}
}
void init(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dist[i][j]=INF;
			r[i][j]=INF;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	init();
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[j],&t[j]);
		}
		///cout << "1111111111111111111111111111111111111";
		for(int i1=1;i1<=k[i];i1++){
			for(int j1=1;j1<=k[i];j1++){
				if(i1==j1){
					continue;
				}
				//cout << a[i1] << ' ' << a[j1] << endl;
				r[a[i1]][a[j1]]=min(r[a[i1]][a[j1]],t[i1]+t[j1]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				continue;
			}
			if(r[i][j]!=INF){
				add(i,j,r[i][j]);
				//cout << i << ' ' << j << ' ' << r[i][j] << endl;
			}
		}
	}
	dj();
	int s,t;
	for(int i=1;i<=Q;i++){
		scanf("%lld%lld",&s,&t);
		printf("%lld\n",dist[s][t]+w[s]+w[t]);
	}
	
	
	return 0;
}