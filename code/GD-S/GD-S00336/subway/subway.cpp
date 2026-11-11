#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+9;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
int a[N];
bool vis[N];
struct node{
	int v,len,h;
};
vector<node> mp[N];
int dist[N];
void dijkstra(int x,int y){
	memset(vis,false,m+1);
	for(int i=1;i<=m;i++){
		dist[i]=inf;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
	q.push({x,5});
	dist[x]=5;
	while(!q.empty()){
		int u=q.top().first;
		int now=q.top().second;
		q.pop();
		vis[u]=true;
		if(dist[u]<now) continue;
		int h2=-1;
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i].v;
			int len=mp[u][i].len;
			if(vis[v]) continue;
			if(dist[v]>dist[u]+len){
				dist[v]=dist[u]+len;
				q.push({v,dist[v]});
			}
		}
	}
	cout<<dist[y]+a[x]+a[y]<<endl; 
}
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		vector<pair<int,int>> b;
		for(int j=1;j<=len;j++){
			int x,y;
			cin>>x>>y;
			b.push_back({x,y});
		}
		for(int j=0;j<b.size();j++){
			for(int k=0;k<b.size();k++){
				if(j==k) continue;
				mp[b[j].first].push_back({b[k].first,b[k].second,i});
				mp[b[k].first].push_back({b[j].first,b[j].second,i});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x,y);
	}
	return 0;
}
