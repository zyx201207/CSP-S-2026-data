#include<bits\stdc++.h>
using namespace std;
int n,m,ans,a[200010];
void dfs(int x,int fa,int sum);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
void dfs(int x,int fa,int sum){
	if(x==m+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=fa+1;i<=n;i++){
		if(x==1)dfs(x+1,i,a[i]);
		else dfs(x+1,i,(sum&a[i]));
	}
}
