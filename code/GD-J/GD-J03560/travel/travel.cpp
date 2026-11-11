#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << "0000";
		return 0; 
	}
	if (s1[0] != s2[0] || s1[1] != s2[1]){
		cout << "1000";
		return 0;
	}
	cout << "11";
	char a = s1[2], b = s2[2];
	if (a - 'A' <= 2)
		a = 'A';
	else
		a = 'D';
		
	if (b - 'A' <= 2)
		b = 'A';
	else
		b = 'D';
	
	if (a == b){
		cout << "1";
		if (s1[2] - s2[2] == 1){
			cout << "1";
		}
		else if (s2[2] - s1[2] == 1){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else{
		cout << "00";
	}
	return 0;
}

//8:56 AC! 100pts
