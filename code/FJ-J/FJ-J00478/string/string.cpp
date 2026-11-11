#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
char ch[5000005];
int n;
int tgcd, cnt;
int ans;
int gcd(int a, int b) {
	if(a < b) {
		swap(a, b);
	}
	int t;
	while(b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		cin >> c[i];
		if(i > 1) {
			tgcd = gcd(tgcd, a[i]);
		}
		else {
			tgcd = a[1];
		}
	}
	for(int i = 1; i <= n; i ++) {
		a[i] /= tgcd;
		for(int j = cnt + 1; j <= cnt + a[i]; j ++) {
			ch[j] = c[i];
		}
		cnt += a[i];
	}
	for(int i = 1; i <= cnt / 2; i ++) {
		if(ch[i] != ch[cnt - i + 1]) {
			ans ++;
		}
	}
	cout << ans * tgcd;
	return 0;
}
