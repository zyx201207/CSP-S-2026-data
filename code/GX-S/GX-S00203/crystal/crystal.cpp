#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long m;
const int MAX = 500000;
long long datas[MAX];

int process() {
	sort(datas, datas + n);
	long long need = 0LL;
	int start = 0;
	int best = 1;
	for (int i = 1; i < n; i++) {
		long long need2 = need + (i - start) * (datas[i] - datas[i-1]);
		while (need2 > m) {
			need2 -= datas[i] - datas[start];
			start++;
		}
		need = need2;
		best = max(i - start + 1, best);
	}
	return best;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		datas[i] = a;
	}
	cout << process() << endl;
	return 0;
}
