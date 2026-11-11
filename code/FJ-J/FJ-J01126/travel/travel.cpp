#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, c;
	string s, t;
	cin >> a >> s >> c >> t;
	if (a == c){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	int b = 0, d = 0;
	b = ((s[0] - 48) * 10 + (s[1] - 48));
	d = ((t[0] - 48) * 10 + (t[1] - 48));
	if (b == d){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	if (s[2] <= 'C' && t[2] <= 'C' || s[2] >= 'D' && t[2] >= 'D'){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if (s > t)swap(s, t);
	if (s[2] == 'A' && t[2] == 'B' || s[2] == 'B' && t[2] == 'C' || s[2] == 'D' && t[2] == 'F'){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
