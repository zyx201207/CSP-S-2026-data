#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N],dp[N];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	dp[0]=2147483647;
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
	}
	cout<<dp[m];
	return 0;
}
