#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<pair<int,int>> v1[500005];
vector<pair<int,int>> v2[505];
vector<pair<int,int>> v3[505];
long long d[500005],vis[500005];
long long dij(int st,int en){
	memset(d,0x3f3f3f3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[st]=0;
	queue<int> q;
	q.push(st);
	vis[st]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:v3[u]){
			if(!vis[v.first]){
				q.push(v.first);
				vis[v.first]=1;
			}
		}
		for(auto v:v3[u]){
			if(d[v.first]>d[u]+v.second){
				d[v.first]=d[u]+v.second;
			}
		}
	}
	return d[en];
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,d,q;
	long long m;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int z,t;
			cin>>z>>t;
			v1[z].push_back({i,t});
			v2[i].push_back({z,t});
			if(!v1[z].empty()){
				for(auto x:v1[z]){
					v3[i].push_back({x.first,x.second+t});
					v3[x.first].push_back({i,x.second+t});
				}
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		long long minn=0x3f3f3f3f;
		for(auto x:v1[u]){
			for(auto y:v1[v]){
				minn=min(minn,dij(x.first,y.first)+x.second+y.second);
			}
		}
		cout<<minn+w[u]+w[v]<<'\n';
	}
	return 0;
} 
