#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 5;

int n;
ll m;
ll a[MAXN];
ll d[MAXN]; //²î·Ö 
ll s[MAXN]; //¹öÄ¾Ç°×ººÍ 
int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	} 
	sort(a + 1, a + 1 + n);
	
    for (int i = 1; i <= n; i ++) {
    	d[i - 1] = a[i] - a[i - 1];
	} 
	
	ll sum = a[1];
	for (int i = 1, j = 1; i < n; i ++) {
	    sum  -= a[j] - a[i - 1];
	    while (j < n && sum + (j - i + 1) * d[j] <= m) {
	    	sum += (j - i + 1) * d[j];
	    	j ++;
		}
		ans = max(ans, j - i + 1);
	}
	cout << ans << '\n';
	return 0;
} 
