#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],ans=-1;
bool vis[100010];
void dfs(int u,long long cnt){
	if(u>m){
		ans=max(ans,cnt);
		return ;
	}
	for(int i = 1;i <= n;i ++){
		if(vis[i]==0){
			vis[i]=1;
			if(u==1) dfs(u+1,a[i]);
			else dfs(u+1,cnt&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0);
		cout<<ans; 
		return 0;
	}
	if(m==1){
		for(int i = 1;i <= n;i ++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1]; 
		for(int i = 2;i <= n;i ++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ans=-1;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++) {
				if(i==j) continue;
				ans=max(ans,(long long)(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	
}
