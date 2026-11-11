#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	long long sum = 0;
	cin >> n;
	int a;
	char c;
	string s = "";
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> c;
		for (int j = 0; j < a; j++) {
			s += c;
		}
	}
	
	for (long long i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i])
			sum ++;
	}
	
	cout << sum;
	
	return 0;
}
