#include <bits/stdc++.h>
using namespace std;

bool check1(char a, char b) {
	if(a == 'A' && b == 'B') return 1;
	if(a == 'B' && b == 'C') return 1;
	if(a == 'A' && b == 'C') return 1;
	if(a == 'D' && b == 'F') return 1;
	return 0;
}

bool check2(char a, char b) {
	if(a == 'A' && b == 'B') return 1;
	if(a == 'B' && b == 'C') return 1;
	if(a == 'D' && b == 'F') return 1;
	return 0;
}

int main() {
	freopen("travel.in","r", stdin);
	freopen("travel.out", "w", stdout);
	string a, c;
	char b1,b2,b3,d1,d2,d3;
	cin >> a >> b1 >> b2 >> b3 >> c >> d1 >> d2 >> d3;
	if(a == c) {
		cout << 1;
	} else cout << 0;
	if(a == c && b1 == d1 && b2 == d2) {
		cout << 1;	
	} else cout << 0;
	if(a == c && b1 == d1 && b2 == d2 && (check1(b3,d3) == 1 || check1(d3,b3) == 1)){
		cout << 1; 
	} else cout << 0;
	if(a == c && b1 == d1 && b2 == d2 && (check1(b3,d3) == 1 || check1(d3,b3) == 1) && (check2(b3,d3) == 1 || check2(d3,b3) == 1)) {
		cout << 1;
	} else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
