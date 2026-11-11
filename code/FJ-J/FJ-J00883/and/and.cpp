#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],ans=0;
int vis[1000001];
void dfs(int sum,int k){
	if(sum==0) return ;
	if(k>m){
		ans=max(ans,sum);
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]++;
			if(k==1) dfs(a[i],k+1);
			else dfs(sum&a[i],k+1);
			vis[i]--;
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
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=1;i<n;i++){
			ans=max(ans,sum);
			sum&=a[i+1];
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
