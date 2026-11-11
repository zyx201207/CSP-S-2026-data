#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int n, a[MAXN], c[MAXN], l;
long long sum, ans, now, head, tail, tl;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	l = n;
	
	for (int i = 1; i <= n; i++) {
		char ch;
		cin >> a[i] >> ch;
		c[i] = ch - 'a' + 1;
		sum += a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (now + a[i] >= sum / 2) {
			head += sum / 2 - now;
			int hd = c[i];
			
			while(head > 0) {
				if (tail == 0) {
					tail += a[l];
					tl = c[l];
					l--;
				}
				
				long long ca = min(head, tail);
				head -= ca;
				tail -= ca;
				if (hd != tl) {
					ans += ca;
				}
			}
			break;
		}
		else {
			now += a[i];
			head += a[i];
			int hd = c[i];
			
			while(head > 0) {
				if (tail == 0) {
					tail += a[l];
					tl = c[l];
					l--;
				}
				
				long long ca = min(head, tail);
				head -= ca;
				tail -= ca;
				if (hd != tl) {
					ans += ca;
				}
			}	
		}
	}
	
	cout << ans;
	
	return 0;
}
