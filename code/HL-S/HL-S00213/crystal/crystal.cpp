#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],dp[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	dp[1]=1;
	int t=m;
	for(int i=1;i<=n;i++){
		int idx=1;
//		cout << "........" << endl;
		for(int j=i+1;j<=n;j++){
			if(idx*(a[j]-a[j-1])<=t){
				t=t-idx*(a[j]-a[j-1]);
				idx++;
			}
		}
		dp[i]=idx;
//		cout << dp[i] << endl;
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
} 
