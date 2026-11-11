//GZ-J00174 ºúî£³¿
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],dp[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		dp[0]=a[i];
		for (int j=min(m,n);j>=1;j--){
			dp[j]=max(dp[j],dp[j-1] & a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
