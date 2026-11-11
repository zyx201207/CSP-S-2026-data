#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
	cin >> n;
	long long a[n + 5];
	char c[n + 5];
	string s;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++)
			s += c[i];
	}
	for (int i = 1;i <= n; i++){
		if (s[i] != s[n - i])
		sum++;
	}
	cout << sum;
    return 0;
}

