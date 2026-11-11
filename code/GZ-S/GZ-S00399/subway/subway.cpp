// GZ-S00399 µËÍûÔÆ 
#include<bits/stdc++.h>
using namespace std;
dis[200005][200005];
int st[200005];
int c[200005];
int head=0,; 
int floyd(){
	st[1]=1;
	c[1]=1;
	head++;
	while(head>0){
		int u=st[head];
		for(auto v:g[u]){
			int b=v.first;
			int w=v.second;
			if(!c[v]){
				head++;
				st[head]=v;
			}
			dis[u][b]=w
			for(int i=1;i<=n;i++){
				
			}
		}
	}
}
int main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	vector<pair<int int> >g[4*n];
	int m,n,d,q;
	cin>>m>>n>>d>>q;
	int a[100005];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		int x;
		cin>>x;
		int a,b;
			cin>>a>>b;
			int v=a+n+j;
			g[a].push_back({v,b});
			g[v].push_back({a,b});
			int c=v;
		for(int i=2;i<=x;i++){
			int a,b;
			cin>>a>>b;
			int v=a+n+j;
			g[a].push_back({v,b});
			g[v].push_back({a,b});
			g[v].push_back({c,0});
			g[c].push_back({v,0});
			c=v;
		} 
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int cnt=0;
		cnt=a[x]+a[y];
		dfs(x,y);
	}
}
