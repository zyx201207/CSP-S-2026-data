#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	long long n;
	long long a[200005],num = 0;
	char b[200005];
	a[0] = 0;
	cin >> n;
	for (long long i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		a[i] += a[i - 1];
	}
	long long r = 1,l = n,rr = 1,ll = a[n];
	for (long long i = 1;i <= a[n] / 2;i++){
		if (r >= l || rr >= ll)
		    break;
		if (b[r] != b[l])
		{
			num += 1;
	    }
		rr+=1;
		ll-=1;
		if (rr > a[r])
			r++;
		if (ll <= a[l - 1])
			l--;
	}
	cout << num;
	return 0;
}
