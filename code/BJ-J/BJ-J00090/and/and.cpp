#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200010],vis[200010];
void dfs(int left,int sum){
	if(left==0){
		ans=max(ans,sum);
		return ;
	}
	if(left==m){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(left-1,a[i]);
			vis[i]=0;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(left-1,sum&a[i]);
			vis[i]=0;
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
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n>2000){
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(m,0);
	cout<<ans;
	return 0;
}