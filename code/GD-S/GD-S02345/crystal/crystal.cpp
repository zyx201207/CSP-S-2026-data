#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5, M = 5e3 + 5;
ll n, m, a[N], c[N], ans, sum, b[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2;i <= n;i++) b[i - 1] = c[i - 1] = abs(a[i] - a[i - 1]);
	for(int i = n - 1;i >= 1;i--) b[i] += b[i + 1];
	for(int i = 1;i <= n - 1;i++) sum += b[i];
	for(int i = n;i >= 1;i--){
		if(sum - c[i] * i <= m){
			cout << i;
			return 0;
		} else {
			sum = sum - c[i] * i;
		}
	}
	return 0;
}
