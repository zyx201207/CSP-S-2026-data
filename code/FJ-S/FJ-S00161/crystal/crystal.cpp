#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],dp[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]<0){
		for(int i=1;i<=n;i++){
			a[i]=a[i]-a[1];
		}
	}
	for(int i=1;i<=n;i++){
		long long s=a[i];
		for(int j=i;j>=1;j--){
			if(s+m>=a[i]*(i-j+1)){
				dp[i]++;
				s+=a[j-1];
			}
		}
	}
	long long maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
	return 0;
}
