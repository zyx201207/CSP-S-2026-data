#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const int N=2005;
bool f1=1,f2=1;
int c,n,m,d,q;
int v[M],k[N],cnt;
int a[N][N],t[N][N];

int e[M*2],w[M*2],nxt[M*2],h[N],idx;
void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,nxt[idx]=h[a],h[a]=idx++;
}

priority_queue<int,vector<int>,greater<int> > pq;
bool vis[N]={};
int dist[N][N];
void dijikstra(int u){
	dist[u][u]=0;
	pq.push(u);
	while(!pq.empty()){
		int t=pq.top();
		pq.pop();
		if(vis[t]==1) continue;
		for(int i=h[t];i!=-1;i=nxt[i]){
			int j=e[i];
			if(dist[u][t]+w[i]<dist[u][j]){
				dist[u][j]=dist[u][t]+w[i];
				if(!vis[j]) pq.push(j);
			}
		}
		vis[t]=1;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>v[i];
	int T;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]!=2) f1=false;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(T!=t[i][j]){
				if(cnt>1) f2=false;
				cnt++;
				T=t[i][j];
			}
			int res=0;
			res=t[i][j]+t[i][j-1];
			add(a[i][j],a[i][j-1],res);
			add(a[i][j-1],a[i][j],res);
		}
	}
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof vis);
		dijikstra(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]<<'\n';
	}
	return 0;
}