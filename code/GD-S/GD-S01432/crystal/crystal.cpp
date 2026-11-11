#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	
	int n;
	long long m;
	cin >> n >> m ;
	
	for(int i = 1;i <= n;i++) {
		cin >> a[i] ;
	}
	
	if(n == 1) {
		cout << 1 ;
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	
	int ans = 0, l = 1;
	long long t = 0;
	for(int i = 2;i <= n;i++) {
		t += (a[i] - a[i - 1]) * (i - l);
		while(t > m) {
			t -= a[i] - a[l];
			l++;
		}
		
		ans = max(ans, i - l + 1);
	}
	
	cout << ans ;
	
	return 0;
}
