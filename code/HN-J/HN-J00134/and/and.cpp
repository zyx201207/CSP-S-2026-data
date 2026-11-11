#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,a[20010],dp[20010];
int dfs(int x,int r){
	if (r==m){
		return a[x];
	}
	for (int i=x;i<n;i++){
		dp[x]=max(dp[x],a[x]&dfs(x+1,r+1));
	}
	return dp[x];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (m==1){
		for (int i=1;i<=n;i++){
			if (a[i]>maxn)	maxn=a[i];
		}
		cout<<maxn;
		return 0;
	}
	if (m==n){
		int k=a[1];
		for (int i=2;i<=n;i++){
			k&=a[i];
		} 
		cout<<k;
		return 0;
	}
	for (int i=1;i<=n-m;i++){
		dfs(i,1);
	}
	for (int i=1;i<=n-m;i++){
		if (dp[i]>maxn)	maxn=dp[i];
	}
	cout<<maxn;
	return 0;
} 
