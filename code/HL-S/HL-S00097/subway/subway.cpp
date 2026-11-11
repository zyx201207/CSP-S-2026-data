#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int c,n,m,d,q;
vector<int> way[600];
vector<int> tim[600];
map<int,int> timl[500010];
vector<int> pas[500010];
int dis[500010];
int w[500010];
int dijkstra(int u,int v){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,u});
	dis[u]=0;
	while(pq.size()){
		auto x=pq.top();
		pq.pop();
		if(x.second==v){
			return x.first;
		}
		for(auto z:pas[x.second]){
			for(int i=0;i<way[z].size();i++){
				int tl=0;
				for(int j=0;j<tim[z].size();j++){
					if(way[z][j]==x.second){
						tl=j;
						break;
					}
				}
				if(dis[way[z][i]]>x.first+tim[z][tl]+tim[z][i]){
					dis[way[z][i]]=x.first+tim[z][tl]+tim[z][i];
					pq.push({dis[way[z][i]],way[z][i]});
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int a,t;
			cin>>a>>t;
			way[i].push_back(a);
			tim[i].push_back(t);
			timl[i][a]=j;
			pas[a].push_back(i);
		}
	}
	for(int i=0;i<q;i++){
		int u,v;
		cin>>u>>v;
		int s=dijkstra(u,v);
		cout<<s+w[u-1]+w[v-1]<<endl;
	}
	return 0;
}