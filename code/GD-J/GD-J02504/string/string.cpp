#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n, cnt;
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while(n--){
		int i;
		char c;
		cin >> i >> c;
		while(i--)s += c;
	}
	int l = 0, r = s.size() - 1;
	while(l < r){
		if(s[l] != s[r])cnt++;
		l++;
		r--;
	}
	cout << cnt;
}
