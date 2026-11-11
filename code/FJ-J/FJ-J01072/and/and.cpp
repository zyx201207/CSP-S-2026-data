#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2000500];
int dfs(int l,int k,int ans){
	if(k>m){
		return ans;
	}
	if(l>n){
		return 0;
	}
	return max(dfs(l+1,k+1,ans&a[l]),dfs(l+1,k,ans));
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,1,pow(2,30)-1);
	return 0;
}
