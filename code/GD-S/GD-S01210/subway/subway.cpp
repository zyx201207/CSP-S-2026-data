#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qs,w[500005],a,t,nnum,ed[505][505],dis[505][505],vis[505],x,y;
int head[505],num=0;
struct pot{
	int sum,d[25],t[25];
}f[500005];
struct edge{
	int next,to,dis;
}e[40005];
void add_e(int from,int to,int dis){
	e[++num].next=head[from],e[num].to=to,e[num].dis=dis,head[from]=num;
}
priority_queue<pair<int,int> > q;
void dij(int s){
	dis[s][s]=0;
	q.push({0,s});
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int sto=e[i].to;
			if(dis[s][sto]>dis[s][u]+e[i].dis){
				dis[s][sto]=dis[s][u]+e[i].dis;
				q.push({-dis[s][sto],sto});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(ed,100,sizeof(ed));
	for(int i=1;i<=n;i++){
		cin>>nnum;
		for(int j=1;j<=nnum;j++){
			cin>>a>>t;
			f[a].sum++,f[a].d[f[a].sum]=i,f[a].t[f[a].sum]=t;
			for(int k=1;k<f[a].sum;k++){
				int ot=f[a].d[k];
				ed[i][ot]=min(ed[i][ot],t+f[a].t[k]),ed[ot][i]=min(ed[i][ot],t+f[a].t[k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			if(i!=j && ed[i][j]<1e17) add_e(i,j,ed[i][j]);
			dis[i][j]=1e17;
		}
	}
	for(int i=1;i<=n;i++) dij(i);
	for(int i=1;i<=qs;i++){
		cin>>x>>y;
		int mins=1e18;
		for(int j=1;j<=f[x].sum;j++){
			int xx=f[x].d[j];
			for(int k=1;k<=f[y].sum;k++){
				int yy=f[y].d[k];
				mins=min(mins,w[x]+w[y]+f[x].t[j]+f[y].t[k]+dis[xx][yy]);
			}
		}
		cout<<mins<<"\n";
	} 
	return 0;
}
