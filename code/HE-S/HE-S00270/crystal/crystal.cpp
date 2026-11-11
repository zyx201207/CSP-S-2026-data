#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> dp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int e;
		cin>>e;
		a.push_back(e);
	}
	sort(a.begin(),a.end());
	long long cnt=0;

	for(int i=n-1;i>=1;i--){
		dp=a;
		long long o=m;
		for(int j=i-1;j>=0;j--){
			if((dp[i]-dp[j])>o){
				break;
			}
			else{
				o-=(dp[i]-dp[j]);
				dp[j]+=(dp[i]-dp[j]);
			}
		}
		long long u=0;
		for(int j=0;j<=n;j++){
			if(dp[j]==dp[i]){
				u++;
			}
		}
		if(u>cnt) cnt=u;
	}
	cout<<cnt;
	return 0;
}
