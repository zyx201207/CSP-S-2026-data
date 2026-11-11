#include<bits/stdc++.h>
using namespace std;
const int N=1010;
bool s[N];
int t[N];
int w[N];
int bian[N][N];
bool f[N];
int dist[N];
vector<pair<int,int>>g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q; //n个线路,m个点 
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
				bian[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=m;i++){
			s[i]=0;
		}
		for(int j=1;j<=k;j++){ //点	 
			int a,b;
			cin>>a>>b; //经过a,距离站台b 
			s[a]=1;
			t[a]=b;
		}
		for(int j=1;j<=m;j++){
			for(int x=1;x<=m;x++){
				if(j!=x && s[j] && s[x]){
					bian[j][x]=min(bian[j][x],t[j]+t[x]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j){
				g[i].push_back({j,bian[i][j]});
				
			}
		}
	}
	for(int j=1;j<=q;j++){
		int x,y;
		cin>>x>>y;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
		for(int i=1;i<=m;i++){
			dist[i]=INT_MAX;
		}
		pq.push({0,x});
		dist[x]=0;
		while(!pq.empty()){
			int u=pq.top().second;pq.pop();
			for(auto k:g[u]){
				int v=k.first,w=k.second;
				if(dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					pq.push({dist[v],v});
				}
			}
		}
		cout<<dist[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
