#include<bits/stdc++.h>
using namespace std;
const int M=500005;
const int N=505;
int n,m,d,p;
long long w[M];
struct node{
    int to;
    long long val;
};
vector<node> e[M+N];
struct edge{
    int v;
    long long w;
    bool operator < (const edge x) const{
        return x.w<w;
    }
};
long long di[M+N];
int vis[M+N];
long long dis[N][N];
priority_queue<edge> q;
struct ysh{
    int id;
    long long w;
}x[25],y[25];
void dij(int x){
    memset(vis,0,sizeof(vis));
    memset(di,0x3f3f3f3f,sizeof(di));
    q.push({x,0});
    di[x]=0;
    while(!q.empty()){
        edge now=q.top();
        q.pop();
        int u=now.v;
        vis[u]=1;
        for(long unsigned int i=0;i<e[u].size();i++){
            int v=e[u][i].to;
            long long w=e[u][i].val;
            if(di[v]>di[u]+w){
                di[v]=di[u]+w;
                if(v>m){
                    dis[x-m][v-m]=dis[v-m][x-m]=di[v];
                }
                
            }
            if(!vis[v]){
                q.push({v,di[v]});
            }
        }
    }
}
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=m+1;i<=n+m;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int u;
            long long v;
            scanf("%d %lld",&u,&v);
            e[u].push_back({i,v});
            e[i].push_back({u,v});
        }
    }
    for(int i=m+1;i<n+m;i++){
        dij(i);
    }
    for(int i=1;i<=p;i++){
		int a,b;
        long long ans=2000000000000000000;
		scanf("%d %d",&a,&b);
		for(int j=1;j<=20;j++){
            x[j].w=-2000000000000000000;
            y[j].w=-2000000000000000000;
            x[j].id=0;
            y[j].id=0;
        }
        for(long unsigned int j=0;j<e[a].size();j++){
            x[j+1].id=e[a][j].to;
            x[j+1].w=e[a][j].val;
        }
        for(long unsigned int j=0;j<e[b].size();j++){
            y[j+1].id=e[b][j].to;
            y[j+1].w=e[b][j].val;
        }
        for(int j=1;j<=d;j++){
            for(int h=1;h<=d;h++){
				if(w[a]+w[b]+dis[y[j].id-m][x[h].id-m]+y[j].w+x[h].w<=0)continue;
                ans=min(ans,w[a]+w[b]+dis[y[j].id-m][x[h].id-m]+y[j].w+x[h].w);
            }
        }
        printf("%lld\n",ans);
	}
    return 0;
}
