#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=505;
const int M=5e5+5;
const int inf=1e9;
int c,n,m,D,q;
//m个节点，n条边 
//步行时间最小 
int w[N];
int k[N],a[M];
vector<PII>g[M];//站厅 
int d[M],vis[M];
inline int Dijkstra(int s,int e){
	d[s]=0;
	priority_queue<PII,vector<PII>,greater<PII>>q;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(PII x:g[u]){
			int v=x.first,w=x.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	/*for(int i=1;i<=m;i++)
		cout<<(d[i]>=1e9?-1:d[i])<<' ';
	cout<<'\n';*/
	return d[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int tt;
		cin>>k[i]>>a[1]>>tt;
		for(int j=2;j<=k[i];j++){
			int T;
			cin>>a[j]>>T;
			g[a[1]].push_back({a[j],T+tt});
			g[a[j]].push_back({a[1],0});
			//tt=T;
		}
	}
	while(q--){
		int x,y;
		for(int i=1;i<=m+m;i++)
			vis[i]=0,d[i]=inf;
		cin>>x>>y;
		int ans=w[x]+w[y];
		cout<<ans+Dijkstra(x,y)<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
