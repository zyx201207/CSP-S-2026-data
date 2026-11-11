#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
vector<pair<int,int> > v[510];
vector<pair<int,int> > g[1000010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		g[i].push_back({m+i,w});
		g[m+i].push_back({m,w});
	}
	//i 站台； m+i 地铁口； m+m+i 线路 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({m+m+i,t});
			g[m+m+i].push_back({a,t});
		}
	}
	while(q--){
//		cout<<"q:"<<q<<endl;
		int x,y;
		cin>>x>>y;
		bool vis[1000510]={};
		priority_queue<pair<int,int> > pq;
		pq.push({0,m+x});
		vis[m+x]=true;
		while(!pq.empty()){
			int w=pq.top().first;
			int u=pq.top().second;
			pq.pop();
//			cout<<u<<'\n';
			if(u==m+y){
				cout<<w<<endl;
//				cout<<"this is the answer\n";
				break;
			}
//			cout<<"v:";
			for(auto hyw : g[u]){
				int t=hyw.first;
				int v=hyw.second;
//				cout<<"("<<v<<' '<<t<<") ";
				if(vis[v]){
//					cout<<"no";
					continue;
				}
				pq.push({w+t,v});
				vis[v]=true;
			}
//			cout<<endl;
		}
	}
	return 0;
}
