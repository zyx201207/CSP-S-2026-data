#include <bits/stdc++.h>
#include <string>
using namespace std;

int f(string s) {
	int l = s.size();
	int j = l/2;
	int i = l-1-j;  // i,j均为下标
	
	int res = 0;
	for (; i >= 0 && j <= l-1; i--, j++) {
		if (s[i] != s[j]) {
			res++;
		}
		// printf("res: %d, i: %d, j: %d\n", res, i, j);
	}
	return res;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n, a;
	char ch;
	string si = "";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> ch;
		for (int j = 0; j < a; j++) {
			si += ch;
		}
	}
	cout << si << endl;
	cout << f(si) << endl;
	
	return 0;
}
