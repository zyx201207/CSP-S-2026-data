#include <bits/stdc++.h>
using namespace std;

const int MAXN(5E5+5);
long long a[MAXN];
long long dp[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
		if(dp[i]>m){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}