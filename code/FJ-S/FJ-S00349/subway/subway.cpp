#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=50005;
int c,n,m,d,q,x,y,ans=1e18,way[505][1001],k[MAXN],w[MAXN];
vector<pair<int,int>> t[MAXN];
vector<int> g[MAXN];
int vis[MAXN][500];
void dfs(int p,int f,int step,int v){
	if(p==v){
		if(f==0){ans=min(ans,step);return;}
		for(int i=0;i<t[p].size();i++)
			if(t[p][i].first==f) ans=min(ans,step+t[p][i].second);
		return;
	}
	if(step>ans) return;
	if(vis[p][f]<=step) return;
	vis[p][f]=step;
	if(f!=0){
		for(int i=1;i<=k[f];i++){
			dfs(way[f][i],f,step,v);
		}
	}
	if(f==0){
		for(int i=0;i<t[p].size();i++) dfs(p,t[p][i].first,t[p][i].second+step,v);
	}
	for(int i=0;i<t[p].size();i++){
		if(t[p][i].first==f) dfs(p,0,step+t[p][i].second,v);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int T;cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>way[i][j]>>T;
			t[way[i][j]].push_back({i,T});
		}
	}
	while(q--){
		int x,y;
		ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			for(int j=0;j<=n;j++){
				vis[i][j]=1e18;
			}
		}
		dfs(x,0,w[x],y);
		cout<<ans+w[y]<<endl;
	}
	return 0;
}
/*
2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
