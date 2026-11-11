#include<bits/stdc++.h>
using namespace std;

const int maa=5e5+5;
long long n,a[maa],m,dp[maa],ans,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	for (int i=2;i<=n;i++){
		f=a[i];
		for (int j=1;j<i;j++){
			dp[i]=dp[i]+abs(a[j]-f);
		}
		if (dp[i]>m){
			break;
		}
		ans++;
	}
	cout <<ans+1;
	return 0;
} 
