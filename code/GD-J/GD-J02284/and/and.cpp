#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans=0;
void dfs(int x,int k,int t){
//	cout<<k<<"\n";
	if(t==m){
		ans=max(ans,k&a[x]);
		return;
	}
	for(int i=x;n-i>=m-t;i++){
		dfs(i+1,k&a[i],t+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,2147483647,1);
	cout<<ans;
	return 0;
}
