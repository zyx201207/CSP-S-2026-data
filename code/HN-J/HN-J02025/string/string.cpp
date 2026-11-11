#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
struct akcsp{
	int a;
	char cx;
}c[maxn];
string s; 
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long num = 0;
	for(int i = 1; i <= n; i++){
		cin >> c[i].a >> c[i].cx;
		for(int j = 1; j <= c[i].a; j++){
			num++;
			s[num] = c[i].cx;
		}
	}
	int q = 0;
	for(int i = 1; i <= n / 2; i++){
		if(s[i] != s[num - i + 1]) q++;
	}
	cout << q;
	return 0;
}	
