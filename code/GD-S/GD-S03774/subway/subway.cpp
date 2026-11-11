#include<bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
const int N=500010,M=10000010,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[N],k[N],x,y;
int minn[514][514],dis[514][514];
int fir[N],cnt;
struct node{
	int v,nxt,c;
}G[M];
void add(int u,int v,int c){
	G[++cnt]={v,fir[u],c};
	fir[u]=cnt;
	G[++cnt]={u,fir[v],c};
	fir[v]=cnt;
}
void input(){
	memset(dis,INF,sizeof(dis));
	memset(fir,-1,sizeof(fir));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			add(i,n+a,t);
		}
	}
}
void solve(){
	input();
	memset(minn,INF,sizeof(minn));
	for(int i=n+1;i<=n+m;i++) for(int j=fir[i];~j;j=G[j].nxt) for(int o=G[j].nxt;~o;o=G[o].nxt) minn[G[j].v][G[o].v]=minn[G[o].v][G[j].v]=min(minn[G[j].v][G[o].v],G[j].c+G[o].c);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(minn[i][j]) dis[i][j]=dis[j][i]=minn[i][j];
	
	for(int o=1;o<=n;o++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=min(dis[i][j],dis[i][o]+dis[o][j]);
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<dis[i][j]<<endl;
	while(q--){
		int ans=INF;
		cin>>x>>y;
		x+=n,y+=n;
		for(int i=fir[x];~i;i=G[i].nxt) for(int j=fir[y];~j;j=G[j].nxt) if(G[i].v!=G[j].v) ans=min(ans,G[i].c+G[j].c+dis[G[i].v][G[j].v]);
		else ans=min(ans,G[i].c+G[j].c);
		cout<<ans+w[x-n]+w[y-n]<<endl;
	}
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
