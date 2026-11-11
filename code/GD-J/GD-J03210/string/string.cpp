#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long num[n];
	char mum[n];
	for(int i = 0;i < n;i++) {
		cin >> num[i] >> mum[i];
	}

	long long c = 0, l = 0, r = n - 1, lc = 1, rc = 1;
	while(l < r) {
		long long cha = min((num[l] - lc), (num[r] - rc));
		if(mum[l] != mum[r]) c += cha + 1;
		lc += cha + 1;rc += cha + 1;
		if(num[l] < lc) {
			lc -= num[l++];
		}
		if(num[r] < rc) {
			rc -= num[r--];
		}
	}

	cout << c << '\n';
	return 0;
}

