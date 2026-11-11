#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
priority_queue<int> q;
int a[N], bb[N], yy[N];
int n, m, ans = 0ll, sum = 0ll, b = 2ll, cnt = 0ll, cnt1 = 0ll, cnt2 = 0ll;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	
	for (int i = 1ll; i <= n; ++i) {
		scanf("%lld", &a[i]);
		
		if (a[i] == i)
			++cnt;
			
		if (i >= 2)
			if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
				++cnt1;
				
		if (a[i] >= -100&&a[i] <= 100)
		++cnt2;
	}
	
	if (cnt == n) {
		printf("%lld", n);
		return 0;
	}
	
	if (cnt1 == n - 1) {
		int oo = a[n] - a[n - 1], oo1 = 0;
		
		for (int i = 2; i <= n; ++i) {
			oo1 += (i - 1) * oo;
			
			if (oo1 > m) {
				ans = i - 1;
				break;
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	
	if (cnt2 == n && n >= 1000) {
		for (int i = 1; i <= n; ++i)
			a[i] += 101;
		
		for (int j = 1; j <= n; ++j)
			for (int i = 1; i <= 201; ++i) {
				if (a[j] == i)
					++yy[i];
			}
		
		for (int i = 1; i <= 201; ++i) {
			int cz = 0, c63 = 0;
			c63 = yy[i];
			
			for (int j = i - 1; j; --j) {
				cz += yy[j] * (i - j);
				
				if (cz <= m)
					c63 += yy[j];
				else
					c63 += (m - (cz - yy[j] * (i - j))) / (i - j);
			}
			
			ans = max(ans, c63);
		}
		
		printf("%lld", ans);
		return 0;
	}
	
	sort(a + 1, a + 1 +n);
	q.push(a[1]);
	
	for (int i = 2; i <= n; ++i) {
		int u = (long long)q.top();

		if (a[i] > u) {
			sum += (long long)q.size() * (long long)(a[i] - u);

			if (sum <= m) {
				q.push(a[i]); ans = max(ans, (long long)q.size());
			}else {
				sum = 0;
				while (!q.empty())
					q.pop(); 
				
				i = ++b;
				q.push(a[i]);
			} 
		} else {
			q.push(a[i]);
	
			sum += q.top() - a[i];
			if (sum <= m)
				ans = max(ans, (long long)q.size());
			else{
				sum = 0;
				while (!q.empty())
					q.pop(); 
				
				i = ++b;
				q.push(a[i]);
			}
				
		}
	}
	
	printf("%lld", ans);
	return 0;
}
// 5 8 -3 -1 2 2 7
