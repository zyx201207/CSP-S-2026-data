#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500,K=5e5,D=20;
int c,n,m,d,q,w[K],k[N],a[N][K],t[N][K];
ll dist[N];
vector<pair<int,ll>> edge[N];
ll dij(int s,int t){
	priority_queue<pair<ll,int>,vector<pair<ll,int>,greater<pair<ll,int>> q;
	memset(dist,0x3f3f,sizeof dist);
	q.push({dist[s]=0,s});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		
		for(auto [w,v]:edge[u])
			if(dist[u]+w<dist[v])
				q.push({dist[v]=dist[u]+w,v});
	}
	return dist[t];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[N];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=j;j++)
			edge[i].push_back({t[i][j]+});
			
	}
	return 0;
}
