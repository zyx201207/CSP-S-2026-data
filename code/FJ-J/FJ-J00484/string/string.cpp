#include<bits/stdc++.h>
using namespace std;
int	n;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string s;
	for(int i = 0; i < n; i++) {
		long long x;
		char c;
		cin >> x >> c;
        for(long long j = 0; j < x; j++) s += c;
	}
	
	string t;
	for(int i = s.size() - 1; i >= 0; i--) {
		t += s[i];
	}
	int l = s.size() / 2;
	
	string ans, cnt;
	if(s == t) cout << 0;
    else {
    	if(s.size() % 2 == 0) {
    		int st = 0;
	    	for(int i = s.size() - 1; i >= l; i--) {
				ans += s[i];
			}
			for(int i = 0; i <= l - 1; i++) {
				cnt += s[i];
			}
			
			for(int i = 0; i < l; i++) {
				if(ans[i] != cnt[i]) {
					st++;
				}
			}
			
			cout << st;
			return 0;
	    } else {
	    	int st = 0;
	    	for(int i = s.size() - 1; i >= l + 1; i--) {
				ans += s[i];
			}
			for(int i = 0; i <= l - 1; i++) {
				cnt += s[i];
			}
			
			for(int i = 0; i < l; i++) {
				if(ans[i] != cnt[i]) {
					st++;
				}
				
			}
			
			cout << st;
			return 0;
		}
	} 
	return 0; 
} 
