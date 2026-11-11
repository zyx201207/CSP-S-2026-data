#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[200005];
void dfs(long long x,long long step,long long num){
	if(step==m){
		ans=max(num,ans);
	}
	else{
		for(int i=x+1;i<=n;i++){
			dfs(i,step+1,num&a[i]);	
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}
