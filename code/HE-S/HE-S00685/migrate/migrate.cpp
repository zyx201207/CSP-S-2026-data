#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ll long long
#define fori(a,b) for(int i=a;i<=b;i++)
#define forj(a,b) for(int j=a;j<=b;j++)
using namespace std;
int n,d,c,t,m,ans,x[200001],vis[5010][5010];
void dfs(int k,int frm){
	vis[k][frm]++,vis[frm][k]++;
	fori(k+1,n){
		if(x[k]+d<x[i]) return ;
		dfs(i,frm);
	}
	return ;
}
void solve(){
	memset(vis,0,sizeof(vis));
	cin>>n>>d;
	ans=0;
	fori(1,n){
		cin>>x[i];
	}
	fori(1,n-1){
		dfs(i,i);
	}
	fori(1,n){
		forj(1,n){
			if(i==j) continue;
			if(vis[i][j]==2) ans++;
		}
	}
	cout<<ans/2<<endl;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
