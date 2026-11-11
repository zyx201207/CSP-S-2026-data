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

int n ,m;
int a[N] ,lst[N] ,siz[N] ,ans[N] ,c[N];
vector<int> G[N];

int main() {
//	freopen("card6.in" ,"r" ,stdin);
	freopen("card.in" ,"r" ,stdin);
	freopen("card.out" ,"w" ,stdout);
	n = read() ,m = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	for (int i = n;i >= 1;i--) {
		if (lst[a[i]]) G[lst[a[i]]].push_back(i);
		else G[i + 1].push_back(i) ,c[i] = a[i];
		lst[a[i]] = i;
	}
	for (int i = 1;i <= n;i++) {
		siz[i] = 1;
		for (auto j : G[i]) siz[i] += siz[j];
		if (c[i]) ans[c[i]] += siz[i];
	}
	for (int i = 1;i <= m;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
