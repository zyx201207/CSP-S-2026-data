#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;

int n;
int a[N];
char c[N];

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int len = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	int mid = len / 2;
	int ans = 0;
	for(int l = 1, r = n; l <= r;){
		if(c[l] != c[r]){
			ans += min(a[l], a[r]);
		}
		if(a[l] > a[r]){
			a[l] -= a[r];
			r --;
		}
		else if(a[r] > a[l]){
			a[r] -= a[l];
			l ++;
		}
		else if(a[l] == a[r]){
			l ++;
			r --;
		}
	}
	cout << ans;
	return 0;
}
