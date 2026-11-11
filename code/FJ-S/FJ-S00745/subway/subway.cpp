#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20005],k[505],x,y,a[505][20005],t[505][20005];
long long ans;
bool vis[20005];
vector< pair<int,int> > v[505];
void dfs(int f,long long sum){
	if(f==y){
		ans=min(ans,sum);
		return;
	}
	vis[f]=true;
	for(int i=0;i<(int)v[f].size();i++)
		for(int j=1;j<=k[v[f][i].first];j++)
			if(sum+t[v[f][i].first][j]+t[v[f][i].first][v[f][i].second]<ans&&!vis[a[v[f][i].first][j]])
				dfs(a[v[f][i].first][j],sum+t[v[f][i].first][j]+t[v[f][i].first][v[f][i].second]);
	vis[f]=false;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int v=1;v<=m;v++)
		cin>>w[v];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back({i,j});
		}
	}
	for(int r=1;r<=q;r++){
		ans=LLONG_MAX;
		cin>>x>>y;
		dfs(x,0);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
} 
