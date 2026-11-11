#include <bits/stdc++.h> 
using namespace std;
const int N=1000005;
int c,t,n,k,s,u,v,vis[N];
long long w,d[N];

vector<pair<int,long long>>e[N]; 
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
void Dijkstra(int S){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	
	d[S]=0;
	q.push({d[S],S});
	
	while(!q.empty()){
		auto tmp=q.top();
		int l=tmp.first;
		int u=tmp.second;
		q.pop();
		
		if(vis[u])
			continue;
		vis[u]=1;
		
		for(auto z:e[u]){
			int v=z.first;
			int w=z.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
} 

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		}
		while(n--){
			Dijkstra(n);
			for(int i=1;i<=n;i++){
				minn=d[i];
			}
			cout<<d[i];
		}
			
		
	}
	
}
