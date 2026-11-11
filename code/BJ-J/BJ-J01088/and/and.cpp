#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500005],dp[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	dp[1]=1;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		
		int j;
		
		for(j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j]&a[i]);
		}
	}
	cout<<dp[m]<<"\n";
	return 0;
}
