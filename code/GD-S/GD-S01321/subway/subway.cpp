#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1005],a[1005];
bool vis[1005];
void dfs(int u,int v){
	int ans=0;
	if(u==v){
		cout<<ans<<endl;
		return;
	}
	ans+=w[u];
	ans+=w[v];
	ans+=a[v-u];
	vis[u]==1;
	dfs(u+1,v+1);
	dfs(u,v+1);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		int s;
		cin>>s;
		for(int i=1;i<=2*s;i++){
			cin>>a[i];
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dfs(u,v);
	}
	return 0;
}
