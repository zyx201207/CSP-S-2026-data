#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N], n, m, sum, mx, num;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
		if(i == 1)
			sum = a[i];
		else
			sum &= a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if(i == j)
				continue;
			num = max(num, a[i] & a[j]);
		}
	}
	if (m == n)
		cout << sum;
	else if (m == 1)
		cout << mx;
	else if (m == 2)
		cout << num;
	else
		cout << 0;
	return 0;
}

