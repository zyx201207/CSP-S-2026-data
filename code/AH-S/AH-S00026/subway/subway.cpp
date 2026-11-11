#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int a[500005],ans=INT_MAX;
vector<int> ve[500005];
int vis[500005];
void dfs(int u,int t){
	if(u==y){
		ans=min(ans,t);
		return;
	}
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u;
			cin>>u;
			ve[u].push(i);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		vis[x]=1;
		dfs(x,a[x]+a[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
