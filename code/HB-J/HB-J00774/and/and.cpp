#include <bits/stdc++.h>
using namespace std;

int count_1(int a) {
	int cnt = 0;
	while(a) {
		if (a&1) cnt++;
		a >>= 1;
	}
	return cnt;
}

int main() {
	freopen("and.in", "r", stdin); 
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[200005], or_res = 0, and_res[20005], res = 0xFFFFFFFF;
	for (int i = 0; i< n; i++) {
		cin >> a[i];
		or_res |= a[i];
	}
	for (int i = 0; i < n; i++) {
		and_res[i] = or_res & a[i];
	}
	sort(and_res, and_res + n, [](int a, int b){return count_1(a) > count_1(b);});
	for (int i = 0; i < m; i++) {
		//cout << bitset<20>(and_res[i]) <<"/" << count_1(and_res[i]) << ' ';
	}
	for (int i = 0; i < m; i++) {
		res &= and_res[i];
		//cout << bitset<32>(and_res[i]) << ' ';
	}
	//cout << "\n";
	cout << res;
	return 0;
}
