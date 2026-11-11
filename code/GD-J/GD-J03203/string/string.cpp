#include <bits/stdc++.h>
#define ll long long
#define _for(i, x, y) for(int i = x;i <= y;i++)
#define fre(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
using namespace std;
ll n, x, l, s;
char ch;
string a;
int main(){
	fre("string")
	cin >> n;
	_for(i, 1, n){
		cin >> x >> ch;
		_for(j, 1, x) a += ch;
	}
	l = a.size();
	if(l % 2 != 0){
		_for(i, 0, l / 2 - 1) if(a[i] != a[n - i]) s++;
		cout << s;
		return 0;
	}
	else{
		_for(i, 0, l / 2 - 1) if(a[i] != a[n - i]) s++;
		cout << s;
		return 0;
	}
	return 0;
}
