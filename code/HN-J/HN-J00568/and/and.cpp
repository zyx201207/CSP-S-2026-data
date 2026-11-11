#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000100],ans;
void dfs(int x,int cnt,int sum){
	if(x==n+1){
		if(cnt==m) ans=max(ans,sum);
		return;
	}
	dfs(x+1,cnt,sum);
	if(cnt==0) sum=a[x];
	dfs(x+1,cnt+1,sum&a[x]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else if(n<=20) dfs(1,0,0),cout<<ans;
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
