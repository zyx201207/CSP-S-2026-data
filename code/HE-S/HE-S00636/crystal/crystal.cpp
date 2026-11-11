#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long dp[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[a[1]]=0;
	int shuzhi=1;
	for(long long i=a[1]+1;i<=a[n];i++){
		if((dp[i-1]+shuzhi)>m){
			break;
		}
		dp[i]=dp[i-1]+shuzhi;
		if((i-1)==a[i-1]){
			shuzhi++;
		}
	}
	cout<<shuzhi;
	return 0;
}
