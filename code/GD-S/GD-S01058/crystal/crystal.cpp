#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
ll read() {
	ll n = 0 ,f = 1; char c = getchar();
	while (c < '0' || c > '9') f = (c == '-') ? -f : f ,c = getchar();
	while (c >= '0' && c <= '9') n = n * 10 + c - '0' ,c = getchar();
	return n * f;
}
template<class T> inline void chkmx(T &x ,T y) { if (y > x) x = y; }
template<class T> inline void chkmn(T &x ,T y) { if (y < x) x = y; }

const int N = 5e5 + 10;

int n; ll m;
ll a[N] ,s[N];

int main() {
//	freopen("crystal4.in" ,"r" ,stdin);
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out" ,"w" ,stdout);
	n = read() ,m = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	sort(a + 1 ,a + 1 + n);
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		int l = 1 ,r = i - 1 ,p = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid) - (s[i - 1] - s[mid - 1]) <= m) r = mid - 1 ,p = mid;
			else l = mid + 1;
		}
		chkmx(ans ,i - p + 1);
	}
	printf("%d\n",ans);
	return 0;
}
