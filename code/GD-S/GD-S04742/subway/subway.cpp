#include<bits/stdc++.h>
#define M 300400
#define D 25
#define N 520
#define int long long
#define inf 0x3f
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q;
int w[M];
int t[N][M];
int p[M][D],l[M];//p[i][j]表示点i所在的第j条线路 l[i]表示点i所在的线路数 
int xl[M];
vector<pii>e[D*M];
priority_queue<pii,vector<pii>,greater<pii>>pq;
void add(int u,int v,int w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
int dis[D*M],vis[D*M];
int dij(int st,int ed){
	memset(dis,inf,sizeof dis);
	memset(vis,0,sizeof vis);
	while(!pq.empty()) pq.pop();
	pq.push({0ll,st});
	dis[st]=0ll;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pii a:e[u]){
			int v=a.first,w=a.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	return dis[ed];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//输入 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		memset(xl,0,sizeof xl);
		for(int j=1;j<=k;j++){
			cin>>xl[j]>>t[i][xl[j]];
			p[xl[j]][++l[xl[j]]]=i;
		}
		for(int j=1;j<k;j++){
			add(xl[j]+(i-1)*m,xl[j+1]+(i-1)*m,0);
		}//建同一层图内的边 
		for(int j=1;j<=k;j++){
			add(xl[j]+(i-1)*m,xl[j]+(n+1)*m,t[i][xl[j]]);
		}
	}
	for(int i=1;i<=m;i++){
		if(l[i]>1){
			for(int j=1;j<l[i];j++){
				for(int jj=j+1;jj<=l[i];jj++){
					add(i+(p[i][j]-1)*m,i+(p[i][jj]-1)*m,t[p[i][j]][i]+t[p[i][jj]][i]); //j号线换乘jj号线 或 jj号线换乘j号线 
//					cout<<t[j][i]<<' ';
				}
			}
		}
	}
	while(q--){
		int st,ed;
		int ans=0;
		cin>>st>>ed;
		cout<<dij(st+(n+1)*m,ed+(n+1)*m)+w[st]+w[ed]<<"\n";
	}
//	cout<<ans;
	
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
