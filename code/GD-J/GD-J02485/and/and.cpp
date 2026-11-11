#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+5;
long long n,k;
long long a[N],dp[N];
/*
4 2
3 15 12 12
*/
long long ans=0;
void dfs(long long i,long long sw,long long sv){
	if(sw==k){
		ans=max(ans,sv);
		return;
	}
	if(i>n){
		return;
	}
	dfs(i+1,sw+1,sv==0?a[i]:sv&a[i]);
	dfs(i+1,sw,sv);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(k==1){
		long long mx=0;
		for(long long i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(k==n){
		cout<<1;
		ans=a[1];
		for(long long i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
