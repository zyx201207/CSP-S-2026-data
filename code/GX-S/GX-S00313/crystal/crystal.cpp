#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,temp=0,cnt=0;
	int a[20000],dp[20000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		dp[i]=a[i]-a[i-1];
	}
	sort(dp,dp+n);
	for(int i=2;i<=n;i++){
		temp=dp[i]+temp;
		cnt++;
		if(temp>m){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
