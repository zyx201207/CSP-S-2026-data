#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
char ch;
string a , s;
int n , ab , cnt , mi;
signed main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out", "w" , stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ab >> ch;
		for (int j = 1; j <= ab; j++) {
			s += ch;
		}
	}
	n = s.size();
	s = ' ' + s;
	a = s;
	for (int i = 1; i <= (n + 1) / 2; i++) {
		if (a[i] != a[n + 1 - i]) cnt++; 
	}
	mi = cnt;
	a = s;
	cnt = 0;
	for (int i = n; i >= (n + 1) / 2; i--) {
		if (a[i] != a[n + 1 - i]) cnt++;
	}
	mi = min(mi , cnt);
	cout << mi;
	return 0;
}
