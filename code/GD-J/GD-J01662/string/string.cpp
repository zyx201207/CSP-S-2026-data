#include<bits/stdc++.h>
using namespace std;
long long n, cnt;
string nw;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	for (long long i = 1; i <= n; i++){
		long long ci;
		char x;
		cin >> ci >> x;
		for (long long i = 1; i <= ci; i++){
			nw += x;
		}
	}
	for (long long i = 0; i <= nw.size() / 2; i++){
		if (nw[i] != nw[nw.size() - i - 1]) {
			cnt++;
		}
	}
	if (nw.size() % 2 == 0) cout << cnt - 1;
	else cout << cnt;
	return 0;
}

