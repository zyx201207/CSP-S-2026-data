#include <bits/stdc++.h>
using namespace std;

#define cout fout
#define cin fin
#define ll long long 

ifstream fin("crystal.in");
ofstream fout("crystal.out");

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector <int> ve(n);
	for (int i = 0; i < n; i++) {
		cin >> ve[i];
	}
	sort(ve.begin(), ve.end()); 
	int l = 0, r;
	ll sum = 0, ans = 1;
	for (r = 1; r < n; r++) {
		sum += (r - l) * (ve[r] - ve[r - 1]);
		while (sum > m) sum -= ve[r] - ve[l++];
		ans = max(ans, r - l + 1ll);
	}
	cout << ans <<'\n';
} 
