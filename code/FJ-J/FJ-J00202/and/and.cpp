#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,m,maxxx=-100;
long long ans1=1073741823;
bool vis[200010];
void dfs(long long k,long long ans){
	if(k>m){
		maxxx=max(maxxx,ans);
//		cout<<maxxx<<' ';
		return;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	} 
	for(int i=k+1;i<=n;i++){
//		if(i==n&&k){
//			cout<<1111111;
//		}
		if(k==1){ 
//			ans=ans&a[i];
			ans=a[i];
			vis[i]=1;
			dfs(k+1,ans);
			vis[i]=0;
		}else{
//			cout<<1111;5
			if(vis[i]==0){
				ans=ans&a[i];
				vis[i]=1;
				dfs(k+1,ans);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long k=ans1,maxx=-1;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		k=k&a[i];
	}
	if(m==n){
		cout<<k;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(n<=2000){
		dfs(1,0);
		cout<<maxxx;
	}
	return 0;
}

