#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10,N=510;
int c,n,m,d,q,w[M],k[N],a[M],t[M],ans;
bool book[M];
vector<pair<int,int>> e[M];
void dfs(int x,int y,int step){
	if(step>ans) return;
	if(x==y){
		ans=min(ans,step);
		return;
	}
	for(int i=0;i<e[x].size();i++){
		int u=e[x][i].first,v=e[x][i].second;
		if(!book[u]){
			book[u]=true;
			dfs(u,y,step+v);
			book[u]=false;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[j]>>t[j];
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(a[j]==a[l]) continue;
				e[a[j]].push_back({a[l],t[j]+t[l]});
			}
		}
	}
	while(q--){
		int x,y;
		ans=1e18;
		cin>>x>>y;
		book[x]=true;
		dfs(x,y,w[x]);
		cout<<ans+w[y]<<"\n";
	}
	return 0;
}
