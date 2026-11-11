#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500050];
vector< pair<long long,long long> >w[500050];
int dis[500050]={};
int bfs(int l,int r){
	int vis[500050]={};
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[l]=0;vis[l]=1;
	queue<int>p;
	p.push(l);
	while(!p.empty()){
		int u=p.front();p.pop();
		
		for(int i=0;i<w[u].size();i++){
			int v=w[u][i].first,r=w[u][i].second;
			if(dis[v]>dis[u]+r&&vis[v]!=1){
				dis[v]=dis[u]+r;
				vis[v]=1;
				p.push(v);
			}
		}
	}
	return dis[r];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		long long k,u,v;
		cin>>k>>u>>v;
		if(k!=1){
			long long u1,v1;
			cin>>u1>>v1;
			w[u1].push_back({u,(v+v1)});
			w[u].push_back({u,(v+v1)});
		}	
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<bfs(l,r)<<endl;
	}
	return 0;
}
