#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
using namespace std;
const int maxn = 2e5 + 5;
int n;
ll sum, ans, a[maxn];
char c[maxn];
string s;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];	 
	}
	int l = 1, r = n;
	while(l < r) {
		if(c[l] != c[r]) {
			if(a[l] >= a[r]) {
				ans += a[r];
				a[l] -= a[r];
				a[r] = 0;
			} else {
				ans += a[l];
				a[r] -= a[l];
				a[l] = 0;
			}
		} else {
			if(a[l] >= a[r]) {
				a[l] -= a[r];
				a[r] = 0;
			} else {
				a[r] -= a[l];
				a[l] = 0;
			}
		}
		if(!a[l]) l++;
		if(!a[r]) r--;
	} 
	cout << ans;
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--) solve();
	return 0;
}

