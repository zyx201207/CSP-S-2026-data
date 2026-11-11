#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
long long n, m;
long long a[N];

int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (long long i=1; i<=n; i++){
		cin >> a[i];
	}

	int flag = 1;
	for (long long i=1; i<=n; i++){
		if (a[i] != i){
			flag = 0;
			break;
		}
	}
	long long i=1;
	if (flag == 1){
		long long cnt = 0;
		while (m>=i){
			m -= i++;
			cnt++;
		}
		if (cnt+1 >= n) cout << n;
		else cout << cnt+1;
		return 0;
	}

	flag = 2;
	for (long long i=1; i<=n-2; i++){
		if (a[i] - a[i+1] != a[i+1] - a[i+2]){
			flag = 0;
			break;
		}
	}
	long long q = a[2] - a[1];  i = q;
	if (flag == 2){
		long long cnt = 0;
		while (m>=i){
			m -= i;
			i += q;
			cnt++;
		}
		if (cnt+1 >= n) cout << n;
		else cout << cnt+1;
		return 0;
	}
	
	sort(a+1, a+n+1);
	cout << m - abs(a[ (n+1)/2 ]) - m;

	
	return 0;
}
