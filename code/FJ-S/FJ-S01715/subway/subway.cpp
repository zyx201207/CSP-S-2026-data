//T2
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int maxn=505;
const int maxm=5e5+5;

int c,n,m,d,Q;
int w[maxm];
vector<int>id[maxm];//此站位于几号线
vector<int>g[maxn];//两个线路之间的连接 
int t[maxm][maxn];//第i个地铁站在第j号线需要的时间 
int len[maxn][maxn];
bool has[maxn][maxn];
int dis[maxn][maxn];
priority_queue<pii,vector<pii>,greater<> >q;

void dijkstra(int st){
	for(int i=1;i<=n;i++){
		dis[st][i]=1e9;
	}
	dis[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		int d=q.top().fi;
		int u=q.top().se;
		q.pop();
		if(d>dis[st][u])
			continue;
		for(int v:g[u]){
			if(dis[st][v]>dis[st][u]+len[u][v]){
				dis[st][v]=dis[st][u]+len[u][v];
				q.push({dis[st][v],v});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>t[a][i];
			id[a].push_back(i); 
		}
	}
	for(int i=1;i<=n;i++){
		has[i][i]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j:id[i]){
			for(int k:id[i]){
				if(j==k)
					continue;
				if(has[j][k]==1){
					len[j][k]=min(t[i][j]+t[i][k],len[j][k]);
					continue;
				}
				len[j][k]=t[i][j]+t[i][k];
				g[j].push_back(k);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	while(Q--){
		int x,y,ans=1e9;
		cin>>x>>y;
		for(int i:id[x]){
			for(int j:id[y]){
				ans=min(ans,t[x][i]+t[y][j]+dis[i][j]);
			}
		}
		ans+=w[x]+w[y]; 
		cout<<ans<<"\n";
	}
	return 0;
}
/*
w其实是无用的只有最后答案需要加上
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
*/
