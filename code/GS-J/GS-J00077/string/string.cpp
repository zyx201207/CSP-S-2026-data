#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n;
	cin >> n;
	string abst = "";
	vector<long long> a(n);
	vector<char> b(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
		for (long long j = 1; j <= a[i]; j++) {
			abst += b[i];
		}
	}
	
	long long sum1 = 0, k = abst.size();
	for (long long i = 0; i < k; i++) {
		k--;
		if (abst[i] != abst[k]) {
			sum1++;
		}
	}
	k = 0;
	long long sum2 = 0;
	for (long long i = abst.size(); i > k; i--) {
		if (abst[i] != abst[k]) {
			sum2++;
		}
		k++;
	}
	
	cout << (long long)min(sum1, sum2) << endl;
	return 0;
}
