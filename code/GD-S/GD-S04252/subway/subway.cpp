#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+10;
int w[N];
vector< pair<int,int> > k[N];
int dis[N]; 
bool vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		int last_id=0;
		int last_t=0;
		for(int i=1;i<=t;i++){
			int x,y;
			cin>>x>>y;
			if(last_id&&last_t){
				k[last_id].push_back({last_t+y,x});
				k[x].push_back({last_t+y,last_id});
			}
			last_id=x;
			last_t=y;
		}
	}
	while(q--){
		priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int>> > p;
		int be,e;
		cin>>be>>e;//begin,end开始和结束节点
		memset(dis,0x3f3f3f3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[be]=0;
		p.push({0,be});
		while(!p.empty()){
			auto it=p.top();
			p.pop();
			if(vis[it.second]) continue;
			vis[it.second]=1;
			int u=it.second;
			for(auto it:k[u]){
				int v=it.second;
				if(vis[v]) continue;
				if(dis[v]>dis[u]+it.first){
					dis[v]=dis[u]+it.first;
					p.push({dis[v],v});
				} 
			}
		}
		cout<<dis[e]+w[be]+w[e]<<endl;
	}
	return 0;
}


