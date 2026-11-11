#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0,vis[200010];
int dp[200010];
void dfs(int sum,int num){
	
	if(num>m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(num==1){
			vis[i]=1;
			dfs(a[i],num+1);
			vis[i]=0;
		} 
		else{
			if(vis[i]==0){
				vis[i]=1;
				dfs(sum&a[i],num+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,1);
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==2){
		dfs(0,1);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n];
	return 0;
}
