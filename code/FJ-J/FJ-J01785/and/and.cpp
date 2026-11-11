#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000];
int dfs(int k,int num,int sum){
	if(num==m+1){
		return sum;
	}
	if(k==n+1){
		return 0;
	}
	int ans=0;
	if(num==0){
		ans=max(ans,dfs(k+1,num+1,a[k]));
	}else{
		ans=max(ans,dfs(k+1,num+1,(sum&a[k])));
	}
	ans=max(ans,dfs(k+1,num,sum));
	return 0; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,0);
	return 0;
}

