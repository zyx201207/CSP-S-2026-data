#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[250000];
void dfs(int x,int num,int k){
	if(k==m){
		ans=max(ans,num);
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,num&a[i],k+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,2147483647,0);
	cout<<ans;
	return 0;
}
