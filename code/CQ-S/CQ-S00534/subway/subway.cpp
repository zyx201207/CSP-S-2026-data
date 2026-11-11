#include<bits/stdc++.h>
using namespace std;
#define maxn 1001000
#define int long long 
int const inf =1e18;
struct node{
	int line,tim;
};
vector<node> g[maxn];
int c,n,m,d,q;
int ano[maxn],wn[510][510];
int cnt=0,h[maxn],to[maxn],nxt[maxn],w[maxn],dis[510][510],vis[maxn];
void add(int u,int v,int c){
	to[++cnt]=v;
	w[cnt]=c;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
void dijstra(int beg){
	for(int i=1;i<=n;i++){
		dis[beg][i]=inf;
		vis[i]=0;
	}
	dis[beg][beg]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,beg));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[beg][u]+w[i]<dis[beg][v]){
				dis[beg][v]=dis[beg][u]+w[i];
				q.push(make_pair(-dis[beg][v],v));
				
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ano[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			wn[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int sta,spd;
			cin>>sta>>spd;
			g[sta].push_back(node{i,spd});
		}

	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j].line;
				int v=g[i][k].line;
				wn[u][v]=min(wn[u][v],g[i][j].tim+g[i][k].tim);
			}
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(wn[i][j]==inf)continue;
			add(i,j,wn[i][j]);
			add(j,i,wn[i][j]);
			//printf("%d %d %d\n",i,j,wn[i][j]);
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<"i"<<i<<" ";
//		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j].line<<" ";
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++){
		dijstra(i);
	}
	for(int i=1;i<=q;i++){
		int xf,xt,ans=inf;
		cin>>xf>>xt;
		for(int j=0;j<g[xf].size();j++){
			for(int k=0;k<g[xt].size();k++){
				node lf=g[xf][j];
				node lt=g[xt][k];
				//printf("%d %d %d\n",lf.line,lt.line,dis[lf.line][lt.line]);
				ans=min(ans,dis[lf.line][lt.line]+lf.tim+lt.tim+ano[xf]+ano[xt]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
