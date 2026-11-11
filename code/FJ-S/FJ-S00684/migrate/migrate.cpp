#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct Node{
	long long v,w;
	friend bool operator<(Node a,Node b){
		return a.w>b.w;
	}
};
long long c,t,n,d,res,a[N],dis[N],vis[N],sum[N];
vector<long long> g[N];
priority_queue<Node> pq;
void dijkstra(long long s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(sum,0,sizeof(sum));
	dis[s]=0,sum[s]=1;
	pq.push({s,0});
	while(!pq.empty()){
		long long u=pq.top().v;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			long long v=g[u][i];
			if(vis[v]) continue;
			if(dis[v]>=dis[u]+1){
				if(dis[v]==dis[u]+1) sum[v]+=sum[u];
				else sum[v]=sum[u];
				dis[v]=dis[u]+1;
				pq.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		res=0;
		for(int i=1;i<=n;i++) g[i].clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++)
				g[i].push_back(j);
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++)
				res+=sum[j]==2;
		}
		cout<<res<<'\n';
	}
	return 0;
}
/*
耗费1145.14ms想正解
打不过暴力 

电脑炸了，尝试重启，然后题面没了，spend 10min 
www 再也不拿暴力程序运行大样例了 www 
题面修改通知刚好在这时候发布，虽然 T2 已经做出来了 
*/
