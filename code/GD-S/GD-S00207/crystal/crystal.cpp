#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005];
int s[500005];
int sum;
int ans;
bool cmp(int a,int b)
{
	return a < b;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j >= 1; j--) {
			sum = a[i] * (i-j+1);
			if(sum - (s[i]-s[j-1]) > m) break;
			ans = max(ans,i-j+1);
		}
	}
	cout << ans;
	return 0;
}
