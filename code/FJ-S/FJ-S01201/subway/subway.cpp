#include<bits/stdc++.h>
#define int long long
#define p pair<int,int>
using namespace std;
int c,n,m,d,q,s,e;
vector<p>g[5000005];
int w[5000005],k[5000005],f[5000005];
int bfs(){
	fill(f+1,f+m+n+1,0);
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
			if(y==e){ans=max(ans,dist+v);}
			f[y]=1;
			q.push({v+dist,y});
		}
	}
	return ans;
}
signed main(){
  	freopen("subway.in","r",stdin);
  	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			g[m+i].push_back({t,a});
			g[a].push_back({t,m+i});
		}
	}
	while(q--){
		cin>>s>>e;
		cout<<bfs()+w[s]+w[e]<<endl;
	}
	return 0;
}

