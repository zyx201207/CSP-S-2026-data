#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
bool vis[1000010];
struct node{
	int u,v;
}a[1000010];
void dfs(int x){
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(a[i].u==x&&vis[a[i].v]==0){
			dfs(a[i].v);
		}
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				ans++;
				dfs(i);
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
