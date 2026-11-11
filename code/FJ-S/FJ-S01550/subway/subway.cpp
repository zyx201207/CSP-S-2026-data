#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mp make_pair
int dis[1002][1002],h[1002],cnt,ww[500002],n,m,d,q;
bool vis[100002];
struct edge{
	int v,w,nxt;
}e[1000002],e2[500002];
void add(int u,int v,int w){
	e[++cnt].w=w,e[cnt].v=v,e[cnt].nxt=h[u],h[u]=cnt;
}
void dijkstra(int x){
	memset(vis,0,sizeof vis);
	dis[x][x]=0;
	priority_queue<pii > pq;
	pq.push(mp(0,x));
	while (!pq.empty()){
		int qwq=pq.top().second;pq.pop();
		if (vis[qwq]) continue;
		vis[qwq]=1;			
		for (int i=h[qwq];i;i=e[i].nxt){
			if (dis[x][qwq]+e[i].w<dis[x][e[i].v]){
				dis[x][e[i].v]=dis[x][qwq]+e[i].w;
				pq.push(mp(-dis[x][e[i].v],e[i].v));
			}
		}
	}
} 
void solve(){
	memset(dis,0x3f,sizeof dis);
	cin>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>ww[i];
	for (int i=1;i<=n;i++){
		int x;cin>>x;
		vector<int> d(x+1),a(x+1);
		for (int j=1;j<=x;j++) cin>>a[j]>>d[j];
		for (int j=1;j<=x;j++) for (int k=j+1;k<=x;k++) add(a[j],a[k],d[j]+d[k]),add(a[k],a[j],d[j]+d[k]);
	}
	for (int i=1;i<=m;i++) dijkstra(i);
	while (q--){
		int x,y;cin>>x>>y;
		cout<<ww[x]+ww[y]+dis[x][y]<<endl;
	}
}	
//B here
int hh[1002],ccnt;
void add2(int u,int v,int w){
	e2[++ccnt].w=w,e2[ccnt].v=v,e2[ccnt].nxt=hh[u],hh[u]=ccnt;
}
int diss[502][502];
bool viss[1002];
void dijkstra2(int x){
	memset(viss,0,sizeof viss);
	diss[x][x]=0;
	priority_queue<pii > pq;
	pq.push(mp(0,x));
	while (!pq.empty()){
		int qwq=pq.top().second;pq.pop();
		if (viss[qwq]) continue;
		viss[qwq]=1;			
		for (int i=hh[qwq];i;i=e2[i].nxt){
			if (diss[x][qwq]+e2[i].w<diss[x][e2[i].v]){
				diss[x][e2[i].v]=diss[x][qwq]+e2[i].w;
				pq.push(mp(-diss[x][e2[i].v],e2[i].v));
			}
		}
	}
} 
vector<int> site[500002];
bool f[502][502];
void solveB(){
	memset(diss,0x3f,sizeof diss);
	cin>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>ww[i];
	int dst=0;
	for (int i=1;i<=n;i++){
		int x;cin>>x;
		vector<int> d(x+1),a(x+1);
		for (int j=1;j<=x;j++){
			cin>>a[j]>>d[j],dst=d[j],site[a[j]].push_back(i);
		} 
	}
//	cerr<<dst<<endl;
	for (int i=1;i<=m;i++){
		int qwq=site[i].size();
		for (int j=0;j<qwq;j++) for (int k=j+1;k<qwq;k++) add2(site[i][j],site[i][k],2*dst),add2(site[i][k],site[i][j],2*dst);
	}
	for (int i=1;i<=n;i++) dijkstra2(i);
	while (q--){
		int x,y;cin>>x>>y;
		int ans=1e18;
		for (auto i:site[x]){
			for (auto j:site[y]){
//				if (dis[i][j]==0){
//					cerr<<i<<" "<<j<<endl;
//				}
				ans=min(ans,diss[i][j]);
			}
		}
//		cerr<<ww[x]+ww[y]<<endl;
		cout<<ans+2*dst+ww[x]+ww[y]<<endl;
//		system("pause");
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _=1;
	int c;cin>>c;
//	cin>>_;
	while (_--){
		if (c<=11) solve();
		else{
			solveB();
		}
	} 
	return 0;
}

