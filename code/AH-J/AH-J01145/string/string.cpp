#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

ll n, a[N], len;
char c[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i], len += a[i];
	ll nowl = 0, nowt1 = 0, nowt2 = a[n], nowidx = n;
	ll ans = 0; bool f = 0;
	for(int i = 1; i <= n; i ++){
		if(nowl + a[i] > len / 2) nowt1 = len / 2 - nowl, f = 1;
		else nowt1 = a[i];
		nowl += a[i];
		while(nowt2 < nowt1){
			if(c[i] != c[nowidx]) ans += nowt2;
			nowt1 -= nowt2;
			nowt2 = a[--nowidx];
		}
		if(c[i] != c[nowidx]) ans += nowt1;
		nowt2 -= nowt1;
		if(nowt2 == 0) nowt2 = a[--nowidx];
		if(f) break;
	}
	cout << ans;
	return 0;
}

