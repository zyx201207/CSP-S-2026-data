#include <bits/stdc++.h>
using namespace std;

int n;
long long sum = 0;
struct info{
	int a;
	char c;
} z[200010], d[200010];

int main (){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "r", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
		char sp;
		scanf ("%d%c%c", &z[i].a, &sp, &z[i].c);
		d[n - i + 1] = z[i];
	}
	int _2 = n / 2;
	for (int i = 1; i <= _2; i++)
		if (z[i].c != d[i].c)
			sum += max (z[i].a, d[i].a);
	printf ("%lld", sum);
	return 0;
}
