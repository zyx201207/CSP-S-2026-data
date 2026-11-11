#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a, cnt;
char c;
string s;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
		for(int j = 1; j <= a; j++)	s += c;
		m += a;
	}
	for(int i = 0; i < m / 2; i++){
		if(s[i] != s[m - 1 - i]){
			cnt++;
		}
	}
	cout << cnt << endl;


	return 0;
}

