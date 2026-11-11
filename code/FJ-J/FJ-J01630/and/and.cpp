#include<iostream>
#define int unsigned long long
using namespace std;
int a[200005];
struct node{
	int v,s;
}dp[200005];
int n,m,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(dp[j].s>=m)continue;
			dp[j].v=dp[j].v&a[j];
			dp[j].s++;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i].v);
	}
	cout<<ans;
	return 0;
}

