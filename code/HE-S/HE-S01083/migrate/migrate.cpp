#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long 
constexpr int N = 2e6+3;
int c, T;
int n;
ll dx[N], d;
void solveA () {
	ll len = dx[2] - dx[1];
	ll cntt = d / len;
	int tans = 0;
	if (cntt == 0 || cntt == 1) {
		printf ("0\n");
		return ;
	}
	cntt = cntt * 2 - 1;
	for (int i = 1; i <= n; ++i)
		if (i + cntt <= n) tans++;
	printf ("%d\n", tans);
	return ;
}
void solveB () {
	
}
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d%d", &c, &T);
	while (T--) {
		scanf ("%d%lld", &n, &d);
		for (int i = 1; i <= n; ++i) scanf ("%lld", &dx[i]);
		if (c == 11 || c == 12)
			solveA ();
	}
	return 0;
}
