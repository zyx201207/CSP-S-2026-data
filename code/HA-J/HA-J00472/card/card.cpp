#include<bits/stdc++.h>
using namespace std;

int n, m, a[200005], mp[300005]; 

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++) {
		vector<int> v;
		for(int j = i; j <= n; j++) {
			int x = lower_bound(v.begin(), v.end(), a[j]) - v.begin();
			if(x >= 0 && x < v.size() && v[x] == a[j]) {
				for(int k = v.size() - 1; k >= x; k--) {
					v.pop_back();
				}
			}
			v.push_back(a[j]);
		}
		for(int j = 0; j < v.size(); j++) {
			mp[v[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		cout<<mp[i]<<" ";
	}
	
	return 0;
}
