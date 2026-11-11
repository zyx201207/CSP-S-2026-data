#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
int a;
char c;
string s;
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a >> c;
		while (a --){
			s += c;
		}
	}
	cout << 0;
	return 0;
}
