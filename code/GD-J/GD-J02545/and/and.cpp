#include<bits/stdc++.h>

using namespace std;
int ans=0;
int n,m;
int a[200010];
void dfs(int b,int t,int num){
	if(t>=m){
		ans=max(ans,num);
		return;
	}
	dfs(b+1,t,num);
	dfs(b+1,t+1,num&a[b]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(2,1,a[i]);
	}
	cout<<ans;
	return 0;
}
