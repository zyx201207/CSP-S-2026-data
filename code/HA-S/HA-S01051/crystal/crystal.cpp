#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
int main ( )  {
	freopen("crystal.in","r", stdin);
	freopen("crystal.out","w", stdout);
	long long n, m;
	long long b = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		d[i] -= d[i - 1];
	}
	if(m == 0){
		for(int i = 1; i <= n; i++){
			if(a[i] == a[i - 1]){
				b++;
			}
		}
		cout << b << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if((a[i] - a[i - 1])*(i - 1)<= m){
			m -= (a[i] - a[i - 1])*(i - 1);
			b++;
		} else {
			break;
		}
	}
	cout << b << endl;
	return 0;
}
