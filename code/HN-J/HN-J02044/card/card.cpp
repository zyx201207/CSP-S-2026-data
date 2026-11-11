#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],e[500010],vis[300010],ans[500010],d[300010];
void dfs(int node){
	int i=e[node];
	if(i==-1) return;
	vis[i]=0;
	dfs(i);
}
void qdfs(int node){
	ans[a[node]]++;
	int i=e[node];
	if(vis[a[i]]==1){
		cout<<a[i]<<' ';
		qdfs(i);
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=0;j<n;j++){
		memset(d,0,sizeof(d));
		memset(e,-1,sizeof(e));
		memset(vis,0,sizeof(vis));
		d[a[j+1]]=1;
		vis[a[j+1]]=1;
		int kj=0;
		for(int i=j+1;i<=n;i++){
			if(vis[a[i]]==1){
				dfs(d[a[i]]);
			}else{
				vis[a[i]]=1;
				e[i-1]=i;
			}
		}	
		for(int u=j+1;u<=n;u++){
			if(vis[u]==1){
				qdfs(u);
				cout<<endl;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
