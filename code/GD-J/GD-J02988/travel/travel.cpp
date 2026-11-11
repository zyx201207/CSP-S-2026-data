#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int tos(string s){
	int res = 0, n = (int)s.size();
	for(int i = 0; i < n; i++){
		res = res * 10 + (s[i] - '0');
	}
	return res;
}
bool sameside(char a, char b){
	return (a <= 'C') == (b <= 'C');
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string tmp1 = "", tmp2 = ""; 
	tmp1 += s1[0], tmp1 += s1[1], tmp2 += s2[0], tmp2 += s2[1];
	int num1 = tos(c1), num2 = tos(c2), line1 = tos(tmp1), line2 = tos(tmp2);
	if(num1 != num2){
		cout << "0000";
		return 0;
	}
	cout << '1';
	if(line1 != line2){
		cout << "000";
		return 0;
	}
	cout << '1';
	if(!sameside(s1[2], s2[2])){
		cout << "00";
		return 0;
	}
	cout << '1';
	if(!(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1)){
		cout << "0";
		return 0;
	}
	cout << '1';
	return 0;
}
