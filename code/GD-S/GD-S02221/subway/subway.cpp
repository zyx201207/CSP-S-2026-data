#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,tim;
};
int c,n,m,d,q,k,a[500010],t[500010],vis[500010],t1,t2,ans=1e9;
int w[500010];
vector<node> v[500010];
void dfs(int x,int sum){
	if (x==t2){
		
		ans=min(ans,sum+w[t2]);
		return ;
		
	}
	for (auto u:v[x]){
		if (vis[u.v]==0){
			vis[u.v]=1;
			dfs(u.v,sum+u.tim);
			vis[u.v]=0;
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			
		}
		for (int j=1;j<k;j++){
			v[a[j]].push_back({a[j+1],t[j]+t[j+1]});
			v[a[j+1]].push_back({a[j],t[j]+t[j+1]});
		}
	}
	for (int i=1;i<=q;i++){
		
		memset(vis,0,sizeof(vis));
		cin>>t1>>t2;
		vis[t1]=1;
		
		dfs(t1,w[t1]);
		cout<<ans<<endl;
	}
	return 0;
}
