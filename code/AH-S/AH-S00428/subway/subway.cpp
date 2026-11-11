#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[500003];
int k[503],a[1010][1010],t[1010][1010];
bool vis[500003];
void dfs(int st,int sd,int sl,int ss){
	if(a[sl][ss]==sd){
		return ;
	}
	if(ans>d)return;
	for(int i=1;i<=k[sl];i++){
		if(!vis[a[sl][i]]){
			dfs(st,sd,sl,ss);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==ss){
				ans+=t[sl][ss]+t[i][j];
				dfs(st,sd,i,j);
				ans-=t[sl][ss]+t[i][j];
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==u){
					ans+=w[u]+w[v];
					dfs(u,v,i,j);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
