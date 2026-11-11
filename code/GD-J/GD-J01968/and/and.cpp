#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005],dp[10005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			maxn=max(maxn,(a[i]&a[j]));
		}
	}
	dp[2]=maxn;
	for(int i=3;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(dp[i-1]>a[j]){
				dp[i]=max(dp[i],(dp[i-1]&a[j]));
			}
		}
	}
	cout<<dp[m];
	return 0;
}
