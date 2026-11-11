#include<bits/stdc++.h>
#define int long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
pair<int,int>vis[2000050];
int root,c,T,n,k,ans,a[2000050];
void dfs(int u,int val){
	if(val<vis[u].fi)
		vis[u]=mk(val,1);
	else if(val==vis[u].fi)
		vis[u].se++;
	for(int i=u+1;i<=n;i++){
		if(a[i]-a[u]>k)break;
		dfs(i,val+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;++i)
				vis[i].fi=LLONG_MAX;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=1;i<=n;++i){
			root=i;
			for(int j=i;j<=n;++j)vis[j].fi=LLONG_MAX;
			dfs(root,0);
			for(int j=i+1;j<=n;++j)
				if(vis[j].se==2) ++ans;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}