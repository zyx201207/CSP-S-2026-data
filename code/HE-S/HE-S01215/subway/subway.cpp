#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[200505];
int w[200005];
bool vis[205005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,z;
	cin>>c>>n>>m>>d>>z;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	while(z--){
	
		int x,y;
		cin>>x>>y;
		queue<pair<int,int> > q;
		q.push({x,0});
		while(1){
			int p=q.front().first,d=q.front().second;
			q.pop();
			if(p==y) {
			cout<<d+w[x]+w[y]<<endl;
			break;
		}
		vis[p]=1;
		for(int i=0;i<g[p].size();i++){
			int ne=g[p][i].first;
			if(!vis[ne]) q.push({ne,d+g[p][i].second});
		}
			for(int i=1;i<=n+m;i++) 
	vis[i]=0;
		}
	}
} 
