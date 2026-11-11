#include <bits/stdc++.h>
using namespace std;

int main (){
	preopen("travel.in", "r", stdin);
	preopen("travel.out", "w", stdout);
	int a1, a2;
	string s1, s2;
	cin >> a1 >> s1 >> a2 >> s2;
	if (a1 == a2){
		cout << 1;
	}else {
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	bool b = true;
	for (int i = 0; i < 2; i++){
		if (s1[i] != s2[i]){
			b = false;
		}
	}
	if (b){
		cout << 1;
	}else {
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	char c1 = s1[2], c2 = s2[2];
	int x1, x2;
	if (c1 == 'A' || c1 == 'B' || c1 == 'C'){
		x1 = 1;
	}else {
		x1 = 0;
	}
	if (c2 == 'A' || c2 == 'B' || c2 == 'C'){
		x2 = 1;
	}else {
		x2 = 0;
	}
	if (x1 == x2){
		cout << 1;
	}else {
		cout << 0;
	}
	if (c1 - c2 == 1 && x1 == x2 || c2 - c1 == 1 && x1 == x2){
		cout << 1;
	}else {
		cout << 0;
	}
}
