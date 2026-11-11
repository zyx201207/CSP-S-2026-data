#include<bits/stdc++.h>
using namespace std;
#define int long long

int n , m , a[201010];
int b[201010];

signed main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	if (m == 1){
		int maxa = 0;
		for (int i = 1; i <= n; i++)
			maxa = max(maxa , a[i]);
		cout << maxa;
		return 0;
	}
	if (m == 2 && n <= 2000){
		int maxb = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				maxb = max(maxb , a[i] & a[j]);
		cout << maxb;
		return 0;
	}
	if (m == n){
		int cnta = a[1];
		for (int i = 2; i <= n; i++)
			cnta = cnta & a[i];
		cout << cnta;
		return 0;
	}
	sort(a + 1 , a + n + 1);
	cout << a[n - m + 1];
	return 0;
}
