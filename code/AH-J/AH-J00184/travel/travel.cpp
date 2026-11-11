#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c, d;
	string a, b;
	cin >> c >> a >> d >> b;
	
	if(c == d) cout << 1;
	if(c != d){
		cout << "0000";
		return 0;
	}
	
	int cnt_a,cnt_b;
	cnt_a = (a[0] - '0') * 10 + a[1] - '0';
	cnt_b = (b[0] - '0') * 10 + b[1] - '0';
	if(cnt_a == cnt_b) cout << 1;
	if(cnt_a != cnt_b){
		cout << "000";
		return 0;
	}
	
	if(a[2] == 'A'){
		if(b[2] == 'B')cout << 11 << " ";
		if(b[2] == 'C')cout << 10 << " ";
		if(b[2] == 'D')cout << "00";
		if(b[2] == 'F')cout << "00";
	}
	if(a[2] == 'B'){
		if(b[2] == 'A')cout << 11 << " ";
		if(b[2] == 'C')cout << 11 << " ";
		if(b[2] == 'D')cout << "00";
		if(b[2] == 'F')cout << "00";
	}
	if(a[2] == 'C'){
		if(b[2] == 'B')cout << 11 << " ";
		if(b[2] == 'A')cout << 10 << " ";
		if(b[2] == 'D')cout << "00";
		if(b[2] == 'F')cout << "00";
	}
	if(a[2] == 'D'){
		if(b[2] == 'B')cout << "00";
		if(b[2] == 'A')cout << "00";
		if(b[2] == 'C')cout << "00";
		if(b[2] == 'F')cout << 11 << " ";
	}
	if(a[2] == 'F'){
		if(b[2] == 'B')cout << "00";
		if(b[2] == 'A')cout << "00";
		if(b[2] == 'C')cout << "00";
		if(b[2] == 'D')cout << 11 << " ";
	}
	return 0;
}
