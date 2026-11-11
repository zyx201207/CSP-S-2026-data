#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char c1[2],s1[3],c2[2],s2[3];
	int a1,a2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1]){
		cout << 1;
	}
	else{
		cout << "0000"; 
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]){
		cout << 1;
	}
	else{
		cout << "000"; 
		return 0;
	}
	if (s1[2] == 'A'){
		a1 = 1;
	}
	if (s1[2] == 'B'){
		a1 = 2;
	}
	if (s1[2] == 'C'){
		a1 = 3;
	}
	if (s1[2] == 'D'){
		a1 = 5;
	}
	if (s1[2] == 'F'){
		a1 = 6;
	}
	if (s2[2] == 'A'){
		a2 = 1;
	}
	if (s2[2] == 'B'){
		a2 = 2;
	}
	if (s2[2] == 'C'){
		a2 = 3;
	}
	if (s2[2] == 'D'){
		a2 = 5;
	}
	if (s2[2] == 'F'){
		a2 = 6;
	}
	if (a1 < 4 && a2 < 4 || a1 > 4 && a2 > 4){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if (a1 + 1 == a2 || a2 + 1 == a1){
		cout << 1;
	}
	else{
		cout << "0";
	}
	return 0;
}
