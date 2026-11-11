#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>


#include <vector>

#define ll long long

using namespace std;

int n;

ll m;

const int maxn = 5e5 + 10;
ll ans;

ll a[maxn];

ll cnt[maxn];

int main() 
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	if(m == 0) {
		cout << 0 << '\n';
		return 0;
	}
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	if (a[1] < 0){
		cnt[1] = 2 * abs(a[1]);
	}
	else
		cnt[1] = a[1];
	
	for(int i = 2; i <= n; i++) {
		if (a[i] < 0){
			cnt[i] += 2 * abs(a[i]);
			a[i] = 2 * abs(a[i]);
		}
		else
			cnt[i] += cnt[i - 1] + a[i];
	}
	if(n == 1){
		cout << 1 << '\n';
		return 0;
	}
	if(a[2] - a[1] <= m) {
		if(a[2] - a[1] == m) {
			cout << 2 << '\n';
			return 0;
		}
		else if(a[2] - a[1] < m && a[3] - cnt[2] > m) {
			cout << 2 << '\n';
			return 0;
		}
	}
	
	for(int i = 2; i <= n; i++) {
		if(((i - 1) * a[i] - cnt[i - 1]) <= m) {
			if(((i - 1) * a[i] - cnt[i - 1]) == m) {
				ans = i;
			}
			else if(((i - 1) * a[i] - cnt[i - 1]) < m && i * a[i + 1] - cnt[i] > m) {
				ans = i;
			}
			else {
				continue;
			}
		}
	}
	
	if(ans != n){
		cout << ans << '\n';
		return 0;
	}
	
	cout << n << '\n';
	
	
	return 0;
	
	
	
}
