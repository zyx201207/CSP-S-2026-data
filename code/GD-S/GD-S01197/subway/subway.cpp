#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii=pair<int,int>;
const int N=1010,M=1e6+10;
int c,n,m,d,q,w[N],vis[M],dis[M],tvis[M];
int a[N][N],t[N][N],k[N];
vector<pii>g[M];
void add(int x,int y,int w){
	g[x].push_back({y,w}),g[y].push_back({x,w}); 
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway1.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][i];
			add(i+m,a[i][j],t[i][j]);
		}
	}
	int tim=0;
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=w[l]+w[r];
		priority_queue<pii,vector<pii>,greater<pii>>q;
		if(vis[l]!=tim)dis[l]=1e18,vis[l]=tim;
		q.push({0,l}),++tim,dis[l]=0;
		while(!q.empty()){
			auto tt=q.top();q.pop();
			int u=tt.second,d=tt.first;
			if(tvis[u]==tim)continue;
			tvis[u]=tim;
			if(u==r){
				ans+=d;
				continue;
			}
			for(auto tv:g[u]){
				int v=tv.first,td=tv.second;
				if(vis[v]!=tim)dis[v]=1e18,vis[v]=tim;
				if(td+d<dis[v])dis[v]=td+d;
				if(!tvis[v])q.push({dis[v],v});
			}
		}
		cout<<ans<<"\n";
	}
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}/*

*/
