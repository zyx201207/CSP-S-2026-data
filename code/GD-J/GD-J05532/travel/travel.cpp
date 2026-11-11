#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0]){
		if (s1[1] == s2[1])
			cout << "1"; 
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "000";
		return 0;
	}
	int a[10];
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		a[0] = 0;
	}
	else{
		a[0] = 1;
	}
	if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
		a[1] = 0;
	}
	else{
		a[1] = 1;
	}
	if (a[0] == a[1]){
		cout << "1";
	}
	else{
		cout << "00";
		return 0;
	}
	int b[10];
	if (s1[2] != 'D'){
		b[0] = s1[2];
	} 
	else{
		b[0] = s1[2] + 1;
	}
	if (s2[2] != 'D'){
		b[1] = s2[2];
	} 
	else{
		b[1] = s2[2] + 1;
	}
	if (abs(b[1] - b[0]) == 1){
		cout << "1";
	}
	else{
		cout << "0";
	}
	return 0;
}
