#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500006], b[500006]; 
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (long long i = 1;i <= n;i++)
		b[i] = a[1] - a[i];
	long long l = 1, r = 1, s = 0, num = 1, cha = 0, c2 = 0;
	while (r <= n) {
		if ((s - cha) <= m)
			num = max(num, r - l + 1), r++, s += (b[r] - c2);
		else
			l++, cha += ( b[l] - c2) * (r - l + 1), c2 = b[l];
		//cout << s << " " << cha << endl;
	}
	cout << num;
}//0 0 4 6 7

