#include<bits/stdc++.h>
using namespace std;
int const N = 2e5+7;
int n,m;
int dp[N][2],ans,f1,f2; 
int a[N];
void dfs(int now,int sum,int cnt){
	if(now>n){
		if(cnt!=m) return;
		ans = max(sum,ans);
		return;
	}
	if(cnt==0){
		dfs(now+1,a[now],cnt+1);
		dfs(now+1,sum,cnt);
		return;
	}
	dfs(now+1,sum,cnt);
	dfs(now+1,sum&a[now],cnt+1);
}
int pow2[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	pow2[0] = 1;
	for(int i=1;i<=30;i++) pow2[i] = pow2[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) f2=1;
		bool f=0;
		for(int j=0;j<=30;j++){
			if(a[i]==pow2[j]-1){
				f = 1;
				break;
			} 
		}
		if(f==0) f1 = 1;
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(m==1 || !f1){
		for(int i=1;i<=n;i++) ans = max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans = a[1];
		for(int i=2;i<=n;i++) ans = ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans = max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(!f2){
		ans = a[n];
		for(int i=2;i<=m;i++) ans=ans&a[n-i+1];
		cout<<ans;
		return 0;
	}
	return 0;
}

