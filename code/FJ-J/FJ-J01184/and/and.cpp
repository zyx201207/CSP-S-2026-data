#include<iostream>
using namespace std;
int n, m;
long long a[200005];
long long u[10000005];
long long v[10000005];
int y[10000005];
int z[10000005];
long long t;
int p, q;
void f(int x){
	if (!x) return ;
	q = 0;
	for (int i = 1; i <= p; i++) {
		for (int j = y[i]+1; j <= n; j++) {
			q++;
			v[q] = u[i] & a[j];
			z[q] = j;
		}
	}
	for (int i = 1; i <= q; i++) u[i] = v[i], y[i] = z[i];
	p = q;
	f(x-1);
}
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		p++;
		u[p] = a[i];
		y[p] = i;
	}
	f(m-1);
	for (int i = 1; i <= p; i++) {
		t = max(t, u[i]);
	}
	printf("%lld", t);
	return 0;
}
