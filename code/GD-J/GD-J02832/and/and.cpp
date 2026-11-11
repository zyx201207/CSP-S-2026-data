#include<bits/stdc++.h>
using namespace std;
long long n,m,jian[523435],v=0,ans=0,vis[523492];
void dfs(int p,int k){
	if(p==m){
		if(ans<k)ans=k;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(p+1,k&jian[i]);
			vis[i]=0;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>jian[i];
	}sort(jian+1,jian+1+n);
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,jian[i]);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
