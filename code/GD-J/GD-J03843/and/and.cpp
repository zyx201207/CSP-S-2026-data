#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;
bool vis[200005];
void dfs(int u,int v){
	if(u==m+1){
		ans=max(ans,v);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(u+1,v&a[i]);
		    vis[i]=1;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}

