#include<bits/stdc++.h>
using namespace std;
int a[200001];
int n,m,ans=-1;
bool vis[200001];
void dfs(int now,int sum){ 
	if(now>m){
		ans=max(ans,sum);
		return;
	}
	if(sum<ans)return;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		if(sum==0)dfs(now+1,a[i]);
		else dfs(now+1,sum&a[i]);
		vis[i]=false;
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
