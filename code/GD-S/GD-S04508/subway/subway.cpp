#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,p,w[500007],k[507],a[507][5007],t[507][5007],st,ed,ans;
bool vis[500007];
vector<int> g[500007];
void dfs(int x,long long z){
	if(x==ed){
		ans=min(ans,z);
		return;
	}
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		for(int j=0;j<=k[g[x][i]];j++){
			if(!vis[a[g[x][i]][j]]){
				dfs(a[g[x][i]][j],z+t[x][j]+w[x]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=p;i++){
		cin>>st>>ed;
		ans=1e9;
		dfs(st,0);
		cout<<ans<<endl;
	}
	return 0;
}
