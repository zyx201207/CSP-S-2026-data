#include<bits/stdc++.h>
using namespace std;
long long n,m,ma;
long long a[500005],dp[500005],dp2[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	if(m == 0){
		cout << 1;
		return 0;
	}
	dp[1] = 0;
	dp2[0] = 0;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
		dp2[i] = dp2[i - 1] + a[i];
	}
	sort(a + 1,a + n + 1);
	dp2[1] = a[1];
	for(long long i = 2;i <= n;i++){
		dp[i] = (a[i] - a[i - 1]) * (i - 1) + dp[i - 1];
		dp2[i] = dp2[i - 1] + a[i];
	}
	for(long long i = 1;i <= n;i++){
		for(long long j = i;j <= n;j++){
			if(i == 1){
				if(dp[j] == m){
					ma = max(ma,j);
				}
			}else{
				if(dp[j] - (a[j] * (i - 1) - dp2[i - 1]) == m){
					ma = max(ma,j - i + 1);
				}
			}
		}
	}
	printf("%ld",ma);
	return 0;
} 
