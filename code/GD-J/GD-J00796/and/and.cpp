#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool vis[200010];
int n,m,ans;
int maxx=-1;
bool bcm(int x,int y){
	return x>y;
}
void dfs(int u,int sum){
	if(u==m+1){
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(u==1) dfs(u+1,a[i]);
		else dfs(u+1,sum&a[i]);
		vis[i]=0;
	}
}
 void solve1(){
 	dfs(1,1);
 	cout<<ans;
 }
 void solve2(){
 	sort(a+1,a+n+1,bcm);
 	cout<<a[m];
 }
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(n<=20){
		solve1();
	}
	else solve2();
	return 0;
} 
