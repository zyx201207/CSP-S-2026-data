#include<bits/stdc++.h>
using namespace std;
long long n, cnt;
string s;
struct Str{
	long long a;
	char c;
};
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	vector<Str>str(n);
	for (long long i = 0; i < n; i++) {
		cin >> str[i].a >> str[i].c;
		for (long long j = 0; j < str[i].a; j++) s += str[i].c;
	}
	for (long long i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) cnt++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
