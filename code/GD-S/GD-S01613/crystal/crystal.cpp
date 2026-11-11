#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll a[N] , b[N] , m;
ll c[N] , maxn , sum;
void fun() {
	if(c[1] > m) {
		cout << 1;
		return ;
	}
	for(int i = 2;i < n;i++) {
		ll x = (c[1] + c[i]) * i / 2;
	    if(x > m) {
	    	cout << i - 1;
	    	return ;
		}
	}
	cout << n;
}
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 2;i <= n;i++) {
		c[i - 1] = a[i] - a[i - 1];
	}
	int cnt = 0;
	for(int i = 1;i < n - 1;i++) {
		if(c[i] == c[i + 1]) cnt++;
		c[i] *= i;
	}
	c[n - 1] *= (n - 1);
	if(cnt == n - 2) {
		fun();
	    return 0;
	}
	b[1] = 1;
	for(int i = 2;i <= n;i++) {
		for(int j = i - 1;j >= 1;j--) {
			sum += a[i] - a[j];
			if(sum >= m) {
				b[i] = i - j + 1;
				break;
			}
		}
		sum = 0;
	}
	for(int i = 1;i <= n;i++) {
		maxn = max(maxn , b[i]);
	}
	cout << maxn;
	
	return 0;
}
