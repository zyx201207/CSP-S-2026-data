#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1, s1, c2, s2;
bool jian1(){
	return c1 == c2;
}
bool jian2(){
	string x1 = s1.substr(0, 2);
	string x2 = s2.substr(0, 2);
	return x1 == x2;
}
bool jian3(){
	int x1 = s1[2] - 65;
	int x2 = s2[2] - 65;
	return x1 / 3 == x2 / 3;
}
bool jian4(){
	int x1 = s1[2] - 65;
	int x2 = s2[2] - 65;
	return abs(x1 - x2) == 1;
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (jian1() == 0){
		cout << "0000"; 
	}
	else if (jian2() == 0){
		cout << "1000";
	}
	else if (jian3() == 0){
		cout << "1100";
	}
	else if (jian4() == 0){
		cout << "1110";
	}
	else{
		cout << "1111";
	}
	return 0;
}
