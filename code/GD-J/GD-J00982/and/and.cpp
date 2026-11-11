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

const int N = 2e5 + 10;

int n ,m;
int a[N];

int main() {
//	freopen("and5.in" ,"r" ,stdin); 
	freopen("and.in" ,"r" ,stdin); 
	freopen("and.out" ,"w" ,stdout); 
	n = read() ,m = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	vector<int> f(n);
	for (int i = 1;i <= n;i++) f[i - 1] = i;
	int ans = 0;
	for (int i = 29;i >= 0;i--) {
		vector<int> g;
		for (auto j : f) if ((a[j] >> i) & 1) g.push_back(j);
		if ((int)g.size() >= m) {
			ans += 1 << i;
			f.swap(g);
		}
	}
	printf("%d\n",ans);
	return 0;
}
