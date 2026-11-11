#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	vector<pair<int, char> > s;
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		int cnt;
		char afb;
		cin >> cnt >> afb;
		s.push_back(make_pair(cnt, afb));
	}
	int l = 0, r = s.size() - 1;
	while (l <= r){
		if (s[l].second == s[r].second){
			if (s[l].first > s[r].first){
				s[l].first -= s[r].first;
				r--;
			}else if (s[l].first < s[r].first){
				s[r].first -= s[l].first;
				l++;
			}else if (s[l].first == s[r].first){
				l++;
				r--;
			}
		}else if (s[l].second != s[r].second){
			if (s[l].first > s[r].first){
				s[l].first -= s[r].first;
				ans += s[r].first;
				r--;
			}else if (s[l].first < s[r].first){
				s[r].first -= s[l].first;
				ans += s[l].first;
				l++;
			}else if (s[l].first == s[r].first){
				ans += s[l].first;
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}// O(n)
