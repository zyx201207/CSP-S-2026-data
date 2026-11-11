#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,m;
int a[N];
int dp[N];

// A
int table[114]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};
bool spflag1=true;
bool in_table(int x) {
	for (int i=0; i<114; i++)
		if (x==table[i])
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		if (!in_table(a[i]))
			spflag1=false;
	}
	
	if (spflag1) {
		sort(a+1,a+n+1,greater<int>());
		int ans=a[1];
		for (int i=2; i<=m; i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if (m==1) {
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
		return 0;
	}
	if (m==2) {
		int ans=0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (i==j)
					continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if (m==n) {
		int ans=a[1];
		for (int i=2; i<=n; i++) {
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=m; j>1; j--) {
			if (dp[j] < (dp[j-1] & a[i]))
				dp[j] = (dp[j-1] & a[i]);
		}	
		if (dp[1]<a[i])
			dp[1]=a[i];
	}
	cout<<dp[m];
	return 0;
}
