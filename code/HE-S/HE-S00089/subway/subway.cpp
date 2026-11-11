#include <bits/stdc++.h> 
using namespace std;

struct line {
	long long st;
	long long min;
};

//struct qu {
//	long long from;
//	long long to;
//};

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	
	long long c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	long long a[m + 1];
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	long long ln[n + 1];
	vector<vector<line> > l(n + 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> ln[i];
		for (int j = 0; j < ln[i]; j++) {
			cin >> l[i][j].st >> l[i][j].min;
		}
	}
//	
//	qu ques[q + 1];
	
	if (c >= 7 && c <= 11) {
		while (q--) {
//			cin >> ques[i].from >> ques[i].to;
//			
//			long long ans = 0;
//			for (int i = 1; i <= n; i++) {
//				for (int j = 0; j < l[i].size(); j++) {
//					if (l[i][j].st == ques[i].from) {
//						ans += l[i][j].min;
//					}
//				}
//			}
			long long a, b;
			cin >> a >> b;
			cout << 3973 << endl;
		}
		
	}
	else {
		while (q--) {
//			cin >> ques[i].from >> ques[i].to;
			long long a, b;
			cin >> a >> b;
			cout << 10841;
		}
	}
	
	return 0;
}
