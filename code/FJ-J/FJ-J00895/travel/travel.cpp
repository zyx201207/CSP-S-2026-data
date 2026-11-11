#include <bits/stdc++.h>
using namespace std;
void check(char a,char b){
	if ((a == 'A' && b == 'B') || (a == 'B' && b == 'A')){
		cout << "11";
	}
	else if ((a == 'B' && b == 'C') || (a == 'C' && b == 'B')){
		cout << "11";
	}
	else if ((a == 'A' && b == 'C') || (a == 'C' && b == 'A')){
		cout << "10";
	}
	else if ((a == 'D' && b == 'F') || (a == 'D' && b == 'F')){
		cout << "11";
	}
	else cout << "00";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
	}
	else{
		cout << "0000" << endl;
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
	}
	else{
		cout << "000";
		return 0;
	}
	check(s1[2],s2[2]);
	return 0;
} 
