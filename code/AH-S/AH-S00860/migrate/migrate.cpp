#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans,vis[5010],cnt[5010][5010];
long long d,a[2000010];
void dfs(int x){
	++vis[x];
	if(vis[x]>6){
		return;
	}
	for(int i=x+1;i<=n;++i){
		if(abs(a[i]-a[x])<=d){
			dfs(i);
		}
	}
	for(int i=x-1;i>=0;--i){
		if(abs(a[i]-a[x])<=d){
			dfs(i);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof vis);
			dfs(i);
			for(int j=1;j<=n;++j){
				if(vis[j]==2){
					++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
