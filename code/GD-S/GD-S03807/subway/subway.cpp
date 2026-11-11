#include<bits/stdc++.h>
#define int long long
#define MAXN 500005
#define N 505
#define pi pair<int,int>
#define mk make_pair
using namespace std;
const int INF=1e18;
int c,n,m,td,tq,d[MAXN],tn[N],cnt[MAXN];
vector<pi>a[MAXN];
int w[N][N],head[N],tcnt,dis[N][N];
struct Edge{
	int value,next,w;
}edge[N*2];
void addedge(int u,int v,int w){
	edge[++tcnt].value=v;
	edge[tcnt].next=head[u];
	edge[tcnt].w=w;
	head[u]=tcnt;
}
priority_queue<pi,vector<pi>,greater<pi> >q;
void dij(int st){
	dis[st][st]=0;q.push(mk(0,st));
	while(!q.empty()){
		int x=q.top().second,d=q.top().first;
		q.pop();
		if(d>dis[st][x])continue;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].value,w=edge[i].w;
			if(dis[st][x]+w<dis[st][y]){
				dis[st][y]=dis[st][x]+w;
				q.push(mk(dis[st][y],y));
			}
		}
	}
}
int fread(){
	char cc=getchar();
	int tans=0,f=0;
	while(!((cc=='-')||(cc>='0'&&cc<='9')))cc=getchar();
	if(cc=='-'){
		cc=getchar(),f=1;
	}
	while(cc>='0'&&cc<='9'){
		tans=(tans<<1)+(tans<<3)+(cc-'0');
		cc=getchar();
	}
	if(f)tans=-tans;
	return tans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&td,&tq);
	c=fread(),n=fread(),m=fread(),td=fread(),tq=fread();
	for(int i=1;i<=m;i++)scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++){
		//scanf("%lld",&tn[i]);
		tn[i]=fread();
		for(int j=1;j<=tn[i];j++){
			int x,y;
			//scanf("%lld%lld",&x,&y);
			x=fread(),y=fread();
			a[x].push_back(mk(y,i));
			cnt[x]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				w[i][j]=dis[i][j]=INF;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<cnt[i];j++){
			for(int k=j+1;k<cnt[i];k++){
				int nx=a[i][j].second,tx=a[i][j].first,ny=a[i][k].second,ty=a[i][k].first;
				if(w[nx][ny]>tx+ty){
					w[nx][ny]=w[ny][nx]=tx+ty;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(w[i][j]!=INF)addedge(i,j,w[i][j]),addedge(j,i,w[j][i]);
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(tq--){
		int x,y;
		//scanf("%lld%lld",&x,&y);
		x=fread(),y=fread();
		int tans=INF;
		for(int i=0;i<cnt[x];i++){
			for(int j=0;j<cnt[y];j++){
				int nx=a[x][i].second,tx=a[x][i].first,ny=a[y][j].second,ty=a[y][j].first;
				tans=min(tans,dis[nx][ny]+tx+ty);
			}
		}
		tans+=d[x]+d[y];
		printf("%lld\n",tans);
	}
	return 0;
}

