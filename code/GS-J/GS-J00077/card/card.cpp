#include <bits/stdc++.h>
using namespace std;

int main() {
	cerr << "42342342342342\n";
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int abc[300012], jilu[300012];
	memset(abc, 0, sizeof(abc));
	memset(jilu, 0, sizeof(jilu));
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > m) {
			return 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		vector<int> b;
		for (int j = i; j < n; j++) {
			if (abc[a[j]] != 1) {
				b.push_back(a[j]);
				abc[a[j]] = 1;				
			}
			else {
				int c = a[j];
				while (b[b.size() - 1] != a[j]) {
					b.pop_back();
				}
				abc[a[j]] = 1;
			}
		}
		
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < b.size(); k++) {
				if (b[k] == j) {
					jilu[j]++;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << jilu[i];
		if (i != m) {
			cout << ' ';
		}
		else {
			cout << endl;
		}
	}
	return 0;
}
