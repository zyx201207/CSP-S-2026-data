#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000],vis[601005],val[601005],qq[600005][3],ans[600005];
vector<pair<int,int> > g[501005];
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i = 1;i<=m;i++) cin>>a[i];
	int k,u,t,idx=m;
	for(int i = 1;i<=n;i++){
		cin>>k;
		int id=++idx;
		for(int j = 1;j<=k;j++){
			cin>>u>>t;
			g[id].push_back({t,u});
			g[u].push_back({t,id});
		}
	}
	for(int i = 1;i<=Q;i++){
		cin>>qq[i][1]>>qq[i][2];
	}
	for(int i = 1;i<=m;i++){
		int x=i;
		while(!q.empty()){
			q.pop();
		}q.push({0,x});
		for(int j = 1;j<=idx;j++) val[j]=1e18,vis[j]=0;
		val[x]=0;
		vis[x]=1;
		while(!q.empty()){
			auto U=q.top();
			int u=U.second;
			q.pop();
			for(auto A:g[u]){
				int w=A.first;
				int v=A.second;
				if(vis[v]==0){
					vis[v]=1;
					val[v]=min(val[v],val[u]+w);
					q.push({val[v],v});
				}
			}
		}for(int j = 1;j<=Q;j++){
			if(qq[j][1]==i) ans[j]=val[qq[j][2]]+a[qq[j][1]]+a[qq[j][2]];
		}
	}
	for(int i = 1;i<=Q;i++) cout<<ans[i]<<endl;
}
