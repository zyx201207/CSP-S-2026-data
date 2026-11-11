#include<iostream>
using namespace std;
string c1, s1, c2, s2;
string r = "0000";
int main(){
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		r[0] = '1';
	}
	if(s1[0] == s2[0] && s1[1] == s2[1] && r[0] == '1'){
		r[1] = '1';
	}
	if(((s1[2] - 'A' < 3 && s2[2] - 'A' < 3) || (s1[2] - 'A' > 2 && s2[2] - 'A' > 2)) && r[1] == '1'){
		r[2] = '1';
	}
	if(((s1[2] - 'A') - (s2[2] - 'A') == 1 || (s1[2] - 'A') - (s2[2] - 'A') == -1) && r[2] == '1'){
		r[3] = '1';
	}
	cout << r;
	return 0;
}
