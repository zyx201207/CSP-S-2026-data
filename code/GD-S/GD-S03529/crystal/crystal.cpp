#include<bits/stdc++.h>
using namespace std;
long long arr[500005] , a[500005];
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	long long n , m , maxn = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	long long sum = 0 , t = 1;
	for(int i = 1; i <= n; i++) {
		arr[i] = a[i] - a[i - 1];
		sum += (i - t) * arr[i];
		while(sum > m)
			sum = sum - (a[i] - arr[t++]);
		maxn = max(maxn , i - t + 1);
	}
	cout << maxn;
	return 0;
}
