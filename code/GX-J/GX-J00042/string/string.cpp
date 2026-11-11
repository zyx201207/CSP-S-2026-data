#include <bits/stdc++.h>
using namespace std;
long long a[200005], n, ans = 0, l, r;
char s[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> s[i];
	l = 1, r = n;
	while(l <= r){
		if(s[l] != s[r]) ans += min(a[l], a[r]);
		if(a[l] < a[r]) a[r] -= a[l], l++;
		else if(a[l] > a[r]) a[l] -= a[r], r--;
		else if(a[l] == a[r]) l++, r--;
	}
	cout << ans;
	return 0;
}
