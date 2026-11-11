#include<bits/stdc++.h>
using namespace std;
long long n , m , a[200005] , o , u;
string s , k , p;
int w(int a , int b) {
	while(a != 0) {
		s += a % 2 + '0';
		a /= 2;
	}
	while(b != 0) {
		k += b % 2 + '0';
		b /= 2;
	}
	if(s.size() < k.size()) {
		p = s;
		s = k;
		k = p;
	}
	for(int i = s.size() - 1 ; i >= 0  ; i++) {
		if(s[i] == k[i] && s[i] == '1') {
			u += pow(2 , i);
		}
		return u;
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	k = INT_MIN;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++) {
		for(int j = i ; j <= n ; j++) {
			if(w(a[i] , a[j]) > o) {
				o = w(a[i] , a[j]);
			}
		}
	}
	cout << o;
	return 0;
}
/*
4 2
3 15 12 12
*/
