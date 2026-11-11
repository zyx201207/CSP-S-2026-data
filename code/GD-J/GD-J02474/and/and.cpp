#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans,vis[25],a[N];
void dfs(int x,int sum){
	vis[x]=1;
	if(x>=m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n-m+1;i++){
		if(!vis[i])dfs(i,sum&a[i]);
	}
	vis[x]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n-m+1;i++)dfs(i,a[i]);
		cout<<ans;
		return 0;
	}
	if(n>2000){
		sort(a+1,a+1+n);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	} 
	return 0;
}
