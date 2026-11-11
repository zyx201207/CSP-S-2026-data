#include<bits/stdc++.h>
using namespace std;
int f[210000],n,m,sum=-1;
int dfs(int c,int ans,int k){
	if(c>=m){
		sum=max(sum,ans);
		return 0;
	}
	for(int i=k;i<=n;i++){
		int u;
		if(ans==-1) u=f[i];
		else u=ans&f[i];
		dfs(c+1,u,i+1);
	}
	return 0; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	dfs(0,-1,1);
	cout<<sum;
	return 0;
} 
