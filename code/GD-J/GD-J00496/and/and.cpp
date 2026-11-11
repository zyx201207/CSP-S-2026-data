#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans,n,m,a[200010],dp[200010],maxn=-1;
void dfs(ll d,ll s,ll sum){
	if(d==n+1){
		if(s==m+1){
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(d+1,m,sum);
	dfs(d+1,m+1,sum&a[d]); 
}
void solve1(){
	dfs(1,0,-1);
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		solve1();
	}else if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}else if(m==n){
		for(int i=1;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
	}
	
	return 0;
}
