#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

long long cnt;
int n, a; 
char c;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a >> c;
		for (int i = 1; i <= a; i++){
			s += c;
		}
	}
	for (long long i = 0, j = s.size() - 1; i < j; i++, j--){
		if (s[i] != s[j]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
