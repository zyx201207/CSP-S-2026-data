#include <bits/stdc++.h>
using namespace std;
int main(){
	string c1, s1, c2, s2;
	bool flag = 0;
	cin >> c1 >> s1 > c2 >> s2;
	for(int i = 0; i < c1.length(); i++){
		if(c1[i] == c2[i]) flag = 1;
	}
	if(flag == 1) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	flag = 0;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == s2[i]) flag = 1;
	}
	if(flag == 1) cout << "1";
	else{
		cout << "000";
		return 0;
	}
	if(s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' || s1[2] >= 'E' && s1[2] <= 'F' && s2[2] >= 'E' && s2[2] <= 'F') cout << "1";
	else{
		cout << "00";
		return 0;
	}
	if(s1[2] <= 'C' && (s2[2] == s1[2] - 1 || s2[2] == s1[2] + 1) || (s1[2] == 'E' && s2[2] == 'F' || s1[2] == 'F' && s2[2] == 'E')) cout << "1";
	else{ 
		cout << "0";
	}
	return 0;
}
