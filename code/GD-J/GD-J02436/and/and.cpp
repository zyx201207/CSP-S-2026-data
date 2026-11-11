#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,dp[333333],maxn,a[555555],x,z;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>dp[1]){
			dp[1]=a[i];
			x=i;
		}
	}
	a[x]=0;
	z++;
	sort(a+1,a+n,cmp);
	for(int i=2;i<=m;i++){
		maxn=0;
		for(int j=1;j<=n-z;j++){
			if(dp[i-1]&a[j]>dp[i]){
				x=j;
				dp[i]=dp[i-1]&a[j];
			}
		}
		z++;
		a[x]=0;
		sort(a+1,a+n-z+1,cmp);
	}
	cout<<a[n];
	return 0;
}
