#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int N = 2e5 + 10;
int n, sum, cnt;
int a[N], la;
char c[N];
map<int, char> mp;
signed main(){
	fin("string.in");
	fout("string.out");
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++){
			mp[la + j] = c[i];
		}
		la += a[i];
	}
//	for(int u = 1; u <= la; u++) cout << mp[u];
	for(int i = 1, j = 1;; ){
//		if(la & 1 && abs(j - i) == 1) break;
		if(i + j >= la) break;
		if(mp[i] != mp[la - j + 1]) sum++;
		if(i > j){
			j++;
		}else if(i < j){
			i++;
		}else i++, j++;
//		cout << i << ' ' << j << '\n';
	}
	cout << sum << '\n';
	return 0;
}
//11:24 我真区吧，只能暴力了 
