#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long ma=-9;
void dfs(long long x,long long su,long long sum){
	if(su<m){
		if(sum==0){
			dfs(x+1,su+1,a[x]);
			if(su+n-x>=m) dfs(x+1,su,sum);
		}else{
			dfs(x+1,su+1,sum & a[x]);
			if(su+n-x>=m) dfs(x+1,su,sum);
		}
	}else{
		ma=max(ma,sum);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum & a[i]);
		}
		cout<<sum;
	}else if(m==1){
		for(int i=1;i<=n;i++) ma=max(ma,a[i]);
		cout<<ma;
	}else{
		dfs(1,0,0);
		cout<<ma;
	}
	return 0;
}
