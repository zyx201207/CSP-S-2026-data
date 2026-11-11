#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5 + 5;
using ll = long long;
int n, l, r;
int a;
char z;
ll c=0;
string s;
int ns=0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	s = "";
	for (int i=0;i<n;i++){
		cin >> a >> z;
		for (int i=0;i<a;i++){
			s += z;
		}
	}
	cout << s;
	l=0,r=s.size()-1;
	for (int i=0;i<s.size();i++){
		if (l >= r) break;
		if (!((int)s[l] == (int)s[r])) {
			c++;
		}
		l++; r--;
	}
	cout << c;
	return 0;
}

