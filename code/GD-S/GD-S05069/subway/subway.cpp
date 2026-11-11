#include<bits/stdc++.h>
using namespace std;
/*
14:44 嗯对，我又来写游记了，上午考得不好aa，下午我想要Ag,,Cu也行 
	  老师说第一题应该是贪心，的确好吧
	  应该是找到一段尽可能长的差之和不超过m的上升子序列 
14:49 ?!前缀和?! 
	  应该是贪心吧、、怎么有股dp味sos 
15:32 ok想出来了，大概是O(n)的样子，是差分贪心 
15:52 其实32时并没有想对，是个n^2所以不行  
16:32 写了个暴力 
17:59 LET'S GOOOOOOOOOOOOOOOOOOOO
      写了一个SPFA应该能过50%以上的T2 
*/
struct E{
	long long v,w;
};
vector<E> e[500510];
long long dist[500510];
bool vis[500510];
int w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,f;cin>>c>>n>>m>>d>>f;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++){
		int k;cin>>k;
		for(int j=1; j<=k; j++){
			int a,t;cin>>a>>t;
			e[i+m].push_back({a,t});
			e[a].push_back({i+m,t});
		}
	}
	while(f--){
		int x,y;cin>>x>>y;
		for(int i=1; i<=m+n; i++){
			dist[i]=1e17;
			vis[i]=false;
		}
		dist[x]=0;
		queue<E> q;
		q.push({x,0});
		while(!q.empty()){
			E cur=q.front();
			q.pop();
			vis[cur.v]=false;
			for(E &i:e[cur.v]){
				if(dist[i.v]>dist[cur.v]+i.w){
					dist[i.v]=dist[cur.v]+i.w;
					if(vis[i.v]==false){
						q.push({i.v,dist[i.v]});
						vis[i.v]=true;
					}
				}
			} 
		}
		cout<<dist[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
