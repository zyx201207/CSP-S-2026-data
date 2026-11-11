#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct st {
	int ts;
	char c;
};
st s[200001], a[100001], b[100001];
int h = 1, t;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	t = n;
	int sum = 0;
	int cnt = 0;
	for(int i = 1;i <= n;++i) {
		cin >> s[i].ts >> s[i].c;
		sum += s[i].ts;
	}
	int ss = 0;
	for(int i = 1;h < t; ++i) {
		int x = abs(s[h].ts - s[t].ts); 
		int nn = min(s[h].ts, s[t].ts); 
		if(s[h].c != s[t].c) {
			
			cnt += nn;
			if(s[h].ts < s[t].ts) {
				h++;
				s[t].ts -= nn;
			} else if(s[h].ts == s[t].ts) {
				h++;
				t--;
			} else {
				t--;
				s[h].ts -= nn;
			}
		} else {
			if(s[h].ts < s[t].ts) {
				h++;
				s[t].ts -= nn;
			} else if(s[h].ts == s[t].ts) {
				h++;
				t--;
			} else {
				t--;
				s[h].ts -= nn;
			}
		}
		
	}
	cout << cnt;
	return 0;
}
