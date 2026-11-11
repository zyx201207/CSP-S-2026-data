#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N][N],n,m,a[N],dxd1,dxd2;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1) {
		int o=INT_MIN;
		for(int i=0;i<n;i++) o=max(o,a[i]);
		cout<<o;
		return 0;
	}
	if(n==m) {
		int k=a[0];
		for(int i=1;i<n;i++) k&=a[i];
		cout<<k;
		return 0;
	}
	for(int i=1;i<n;i++) {
		dp[i][0]=a[i]&a[0];
		dp[0][i]=a[i]&a[0];
	}
	for(int i=1;i<n;i++) {
		for(int j=1;j<n;j++) {
			if(i!=j) {
				dp[i][j]=max(a[i]&a[j],dp[i-1][j-1]);
				dxd1=i;
				dxd2=j;
				//cout<<i<<'/'<<j<<' '<<a[i]<<'/'<<a[j]<<' '<<(a[i]&a[j])<<'/'<<dp[i-1][j-1]<<' '<<dp[i][j]<<endl;
	    	}
		}
	}
	cout<<dp[dxd1][dxd2];
	return 0;
}
/*
4 2
3 15 12 12
*/
