#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[200005],ans=0;

void dfs(long long x,long long cnt,long long k){
	if(cnt==m){
		ans=max(ans,x);
		return;
	}
	for(long long i=k;i<=n;i++){
		dfs(x&a[i],cnt+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	for(long long i=1;i<=n;i++){
		dfs(a[i],1,i+1);
	}
	
	cout<<ans;
	return 0;
}
//May all the beauty be blessed.
