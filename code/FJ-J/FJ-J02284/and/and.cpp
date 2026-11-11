#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,m,ans;
void dfs(int k,int g,int sum){
	if(k==n+1||g==m){
		if(g==m)ans=max(ans,sum);
		return ;
	}
	dfs(k+1,g+1,sum&a[k]);
	dfs(k+1,g,sum);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++)sum&=a[i];
		cout<<sum;
		return 0;
	}
	dfs(1,0,LLONG_MAX);
	cout<<ans;
	return 0;
} 
