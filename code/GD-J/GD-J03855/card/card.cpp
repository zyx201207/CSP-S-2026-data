#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
vector<int> s;
int ans[300005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		//cout << a[i] << " ";
	}
	for(int i = 0; i < n; i++) {
		//cout << i << " ";
		for(int j = i; j < n; j++) {
			//cout << j << " ";
			bool flag = true;
			int pos = s.size() - 1;
			for(int k = 0; k < s.size(); k++) {
				//cout << k << " ";
				if(s[k] == a[j]) {
					pos = k + 1;
					flag = false;
					break;
				}
				//cout << s[k] << " ";
			}
			if(flag == false) {
				for(int k = pos; k < s.size(); k++) {
					s.erase(s.begin() + k);
				}
			}
			if(flag == true) {
				s.push_back(a[j]);
			}
		}
		for(int j = 0; j < s.size(); j++) {
			ans[s[j]]++;
		}
		s.clear();
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
