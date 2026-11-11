#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2005],ans=0,dp[2005][2005];
int n,m;
void dfs(int k,int sum,int s){
	if(k>n+1)
		return;
	if(s==m){
		ans=max(ans,sum);
		return;
	}
	
	if(sum==-1)
		dfs(k+1,a[k],s+1);
	else
		dfs(k+1,sum&a[k],s+1);
	dfs(k+1,sum,s);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	int tmp1=a[1],tmp2=a[1],tmp3=a[1];
	bool f=1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		tmp1=max(tmp1,a[i]);
		tmp2&=a[i];
		tmp3=min(tmp3,a[i]);
		if(a[i]!=i-1)
			f=0;
	}	
	if(m==1)
		cout<<tmp1<<endl;
	else if(m==n){
		cout<<tmp2<<endl;
	}
	else if(n<=2000){
		dfs(1,-1,0);
		cout<<ans<<endl;
	}
	else if(m==n-1)
		cout<<(tmp2&tmp3)<<endl;
	else if(f==1){
		if(n&1){
			cout<<(n&(n-1))<<endl;
		}
		else{
			cout<<((n-2)&(n-1))<<endl;
		}
	}
	else{
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
			ans&=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
