#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> cards;
	map<int, long long> mp; 
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		cards.push_back(k);
	}
	for (int i = 1; i <= n; i++) {
		
		vector<int> vec;
		unordered_map<int, bool> cnt;
		int j = i - 1;
		for (; j < cards.size(); j++) {
			auto c = cards[j];
			if (!cnt[c])
				cnt[c] = true, vec.push_back(c);
			else {
				while(vec[vec.size() - 1] != c)
					cnt[vec[vec.size() - 1]] = false, vec.pop_back();
			}
		}
		for (int p = 1; p <= m; p++) {
			mp[p];
			if (cnt[p]) mp[p]++;
		}
	}
	
	for (auto p : mp) {
		cout << p.second << ' ';
	}
	cout << '\n';
	
	return 0;
}
