#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],a[510][5010],t[510][5010],vis[40],sj[40][40],js[40],k[5010];
vector<long long>g[40];
void dfs(long long x,long long y){
	if(x==y){
		return ;
	}
	for(auto v:g[x]){
		if(vis[v]==0){
			js[v]=min(js[v],js[x]+sj[x][v]);
			vis[v]=1;
			dfs(v,y);
			vis[v]=0;
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1 ; i<=m ; i++){
		cin>>w[i];
	}
	for(int i=1 ; i<=n ; i++){
		cin>>k[i];
		for(int j=1 ; j<=k[i] ; j++){
			cin>>a[i][j]>>t[i][j];
			for(int o=1 ; o<j ; o++){
				g[a[i][j]].push_back(a[i][o]);
				g[a[i][o]].push_back(a[i][j]);
				sj[a[i][j]][a[i][o]]=t[i][j]+t[i][o];
				sj[a[i][o]][a[i][j]]=t[i][j]+t[i][o];
			}
		}
	}
	while(q--){
		for(int i=1 ; i<=40 ; i++){
			vis[i]=0;
			js[i]=1e5;
		}
		long long x,y;
		cin>>x>>y;
		js[x]=0;
			dfs(x,y);	
		cout<<js[y]+w[x]+w[y]<<endl;
	}
	return 0;
}