#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10; 

long long n,m,a[N],s[N],cnt[N];

long long dp[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >>n >>m;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++){
		s[i-1]=abs(a[i]-a[i-1]);
	}
	sort(s+1,s+n+1);
	long long ans=0;
	dp[1]=s[1];
	for(int i = 1;i < n;i++){
		if(dp[i]+dp[i-1] <=m){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
