#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long l = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		char c;
		cin >> a >> c;
		l += a;
		for(int j = 0; j < a; j++)s += c;
	}
	int ans = 0;
	for(long long i = 0, j = l - 1; i <= j; i++, j--){
		if(s[i] != s[j]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
