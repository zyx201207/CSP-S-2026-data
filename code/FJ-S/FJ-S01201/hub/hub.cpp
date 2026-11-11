#include<bits/stdc++.h>
#define int long long
#define p pair<int,int>
using namespace std;
int c,t,f[100005],n,k;
vector<p>g[100005];
int bfs(int s,int e){
	fill(f+1,f+n+1,0);
	int ans=0;
	priority_queue<p,vector<p>,greater<p>>q;
	q.push({0,s});
	f[s]=1;
	while(!q.empty()){
		int x=q.top().second;
		int dist=q.top().first;
		q.pop();
		for(int i=0;i<g[x].size();i++){
			int v=g[x][i].first;
			int y=g[x][i].second;
			if(f[y]){
				continue;
			}
			if(y==e){ans=max(ans,dist+v+1);}
			f[y]=1;
			q.push({v+dist+1,y});
		}
	}
	return ans;
}
signed main(){
  	freopen("hub.in","r",stdin);
  	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)g[i].clear();
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back({1,u});
			g[v].push_back({1,u});
		}
		int anss=-1e9;
		for(int i=1;i<=n;i++){
			int ans=1e9;
			for(int j=i;j<=n;j++){
				ans=min(ans,bfs(i,j));
			}
			anss=max(ans,anss);
		}
		cout<<anss<<endl;
	}
	return 0;
}

