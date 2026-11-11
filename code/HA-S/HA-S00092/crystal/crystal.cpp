#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll m;

const int N = 500000;
ll a[N + 1];

ll read(){
	ll x = 0; bool flag = false;
	while (true){
		char c = getchar();
		if (c == '-'){
			flag = true;
		} else if ('0' <= c && c <= '9'){
			x = x * 10 + (c - '0');
		} else {
			break;
		}
	}
	return flag ? -x : x;
}


int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();

//	scanf("%d %lld", &n, &m);
//	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	
	sort(a + 1, a + n + 1);
	
	int l = 1, res = 1;
	ll sum = 0;
	for (int r = 1; r <= n; r++){
		sum += a[r];
		while (sum + m < a[r] * (r - l + 1)) {
			sum -= a[l++];
		}
		res = max(res, r - l + 1);
	}
	printf("%d", res);
	
	return 0;
}
