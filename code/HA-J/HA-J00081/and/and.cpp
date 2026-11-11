#include <bits/stdc++.h>
using namespace std;

vector<int> Glo_data;

bool GloFun_Cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	cout.tie(nullptr);
	string FILENAME = "and";
	string IFILE = FILENAME + ".in";
	string OFILE = FILENAME + ".out";
	freopen(IFILE.c_str(), "r", stdin);
	freopen(OFILE.c_str(), "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		
		Glo_data.push_back(a);
	}
	
	unsigned int cur = (1 << 31) - 1;
	unsigned int ans = 0;
	
	for (int i = 30; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			Glo_data[j] &= cur;
		}
		sort(Glo_data.begin(), Glo_data.end(), GloFun_Cmp);
		
		unsigned int cans = cur;		
		for (int j = 0; j < m; j++) {
			cans &= Glo_data[j];
		}
		
		ans = max(ans, cans);
		cur >>= 1;
	}
	
	cout << ans;
}
