//GZ-S00001 ÀîÀ¤Ôª
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=505,M=1005;
int c,n,m,d,q;
int w[M],k[N];
int t[N][M],a[N][M];
int e[M],ww[M],h[M],ne[M],idx=0;
int dist[M][M],vis[M];
void add(int a,int b,int c){
	e[idx]=b;
	ww[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dij(int x){
	dist[x][x]=0;
	for(int i=1;i<=m;i++) vis[i]=false;
	priority_queue< PII , vector<PII> , greater<PII> > q;
	q.push({0,x});
	while(!q.empty()){
		PII u=q.top();
		q.pop();
		if(vis[u.second]) continue;
		vis[u.second]=true;
//		cout<<"||"<<u.second<<endl<<endl;
		for(int i=h[u.second];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[x][j]<=dist[x][u.second]+ww[i]||vis[j]) continue;
			dist[x][j]=dist[x][u.second]+ww[i];
			q.push({dist[x][j],j});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++) if(k[i]==2) add(a[i][1],a[i][2],t[i][1]+t[i][2]),add(a[i][2],a[i][1],t[i][1]+t[i][2]);
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dist[i][j]=1e18;
	for(int i=1;i<=m;i++) dij(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
