#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	long long n, m, a[200005], sum = 0;
	scanf ("%lld %lld", &n, &m);
	for (long long i = 1; i <= n; i ++){
		cin >> a[i];
	}
	cout << a[n];
	return 0;
}
