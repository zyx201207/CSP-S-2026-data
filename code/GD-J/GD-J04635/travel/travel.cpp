#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a, b, c, d;
ll n, m, x, y, u, v;
ll sl(string s){
	return (s[0] - '0') * 10 + (s[1] - '0');
}
ll ck(string s){
	return s[2] - 'A' + 1; 
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	n = sl(a);
	m = sl(b);
	x = sl(c);
	y = sl(d);
	u = ck(b);
	v = ck(d);
	if(u > v){
		swap(u, v);
	}
	bool ok = 1;
	if(n == x){
		cout << 1;
	}
	else{
		ok = 0;
		cout << 0;
	}
	if(m == y && ok){
		cout << 1;
	}
	else{
		ok = 0;
		cout << 0;
	}
	if(((u <= 3 && v <= 3) || (u > 3 && v > 3)) && ok){
		cout << 1;
	}
	else{
		ok = 0; 
		cout << 0;
	}
	if(ok){
		if(u == 1 && v == 2){
			cout << 1;
		}
		else if(u == 2 && v == 3){
			cout << 1;
		}
		else if(u == 4 && v == 5){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	return 0;
}
