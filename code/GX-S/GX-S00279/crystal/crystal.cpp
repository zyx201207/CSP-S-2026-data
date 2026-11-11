#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 6;

inline ll rd(){
	char c;
	bool flag = 0;
	while((c = getchar()) && (c < '0' || c > '9')){
		flag = (c == '-');
	}
	ll res = c - '0';
	while((c = getchar()) && (c >= '0' && c <= '9')){
		res = (res << 3) + (res << 1)  + c - '0';
	}
	return flag ? -res : res;
}

inline void wr(ll x){
	if (x < 0){
		putchar('-');
	}else{
		if (x > 9) wr(x / 10);
		putchar(x % 10 + '0');
	}
}

int n,ans;
ll sums[N],a[N],m;

int solve(int p){
	int l = 1,r = p;
	while(l <= r){
		int mid = (l + r) >> 1;
		if ((a[p] * (p - mid)) - (sums[p - 1] - sums[mid - 1]) <= m) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = rd(),m = rd();
	for (int i = 1; i <= n; ++i){
		a[i] = rd();
	}
	sort(a + 1,a + 1 + n);
	for (int i = 1; i <= n; ++i){
		sums[i] = sums[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i){
		ans = max(ans,i - solve(i) + 1);
	}
	wr(ans);
	return 0;
}

