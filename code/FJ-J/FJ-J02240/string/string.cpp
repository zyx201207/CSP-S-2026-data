#include <iostream>
using namespace std;

int main() {
	string s[300000];
	string c;
	double a, temp;
	int n = 0;
	int need = 0;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> temp;
		cin >> c;
		for (int j = n; j < n + temp; j++) {
			s[j] = c;
		}
		n += temp;
	}
	for (int i = 0; i <= n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			need++;
		}
	}

	cout << need;
	return 0;
}
