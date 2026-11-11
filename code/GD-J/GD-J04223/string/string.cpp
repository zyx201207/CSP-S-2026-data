#include<bits/stdc++.h>
using namespace std;
int x[100000];
int main() {//can ccf go die? suoyicuonale

	freopen("string.in", "s", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	
	string c;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		cin >> c[i];
	}
	string s;
	int e = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= x[i]; j++) {
			e++;
			s[e] = c[i];
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= e/2; i++) {
		if(s[i] != s[e - i + 1]){
		cnt++;}
	}
	cout << cnt;
	return 0;
}
