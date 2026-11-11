#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using ull = long long;
int main() {
	/*fopen("string.in", cin);
	fopen("string.out", cout);*/
	ios::sync_with_stdio(false);
	cin.tie(0);
	ull n;
	cin >> n;
	string S = "";
	while(n--) {
		int sum;
		cin >> sum;
		char c;
		cin >> c;
		while (sum--) {
			S.push_back(c);
		}
	}
	ull S_length = S.length();
	ull S_length_2 = S_length / 2;
	ull ans = 0;
	for (ull i = S_length - 1, j = 0; j <= S_length_2; i--, j++) {
		if (S[i] != S[j]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
