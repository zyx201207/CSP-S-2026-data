#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N],n,dt;
int c,q;
bool vis[N];
int d[N],ans;
void dfs(int x,int dis){
	if(vis[x]==1&&d[x]==dis){
		ans++;
		return;
	}else{
		vis[x]=1;
		d[x]=dis;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=dt){
			dfs(i,dis+1);
		}
	}
	return;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		ans=0;
		cin>>n>>dt;
		for(int i=1;i=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dfs(i,0);
			memset(vis,0,sizeof(vis));
			memset(d,0,sizeof(d));
		} 
		cout<<ans;
	}
	return 0;
}
