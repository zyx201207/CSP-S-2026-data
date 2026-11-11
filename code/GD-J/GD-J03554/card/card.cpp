#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], ans[300010];
vector<int> s;
int fnd(int x) {
	for(int i=0; i<s.size(); i++) {
		if(s[i] == x) {
			return i;
		}
	}
	return n+1;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	bool A = 1;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(i>1 && a[i]<a[i-1]) {
			A = 0;
		}
	}
	
	if(A) {
		s.push_back(a[1]);
		for(int T=1; T<=n; T++) {
			s.clear();
			for(int i=T; i<=n; i++) {
				if(a[i]>a[i-1] || i==T) {
					s.push_back(a[i]);
				}
			}
			for(int i=0; i<s.size(); i++) {
				ans[s[i]]++;
			}
		}
		for(int i=1; i<=m; i++) {
			cout << ans[i] << " ";
		}
		return 0;
	}
	
	for(int T=1; T<=n; T++) {
		s.clear();
		for(int i=T; i<=n; i++) {
			if(fnd(a[i]) != n+1) {
				for(int j=fnd(a[i]); j<s.size(); j++) {
					s[j] = 0;
				}
			}
			s.push_back(a[i]);
		}
		for(int i=0; i<s.size(); i++) {
			ans[s[i]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
