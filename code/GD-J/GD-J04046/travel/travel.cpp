//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int c1, c2, line1, line2;
//char col1, col2;
//string s1, s2;
//
//int main(){
//	cin >> c1 >> s1 >> c2 >> s2;
//	line1 = (s1[0]-'0') * 10 + s1[1]-'0';
//	line2 = (s2[0]-'0') * 10 + s2[1]-'0';
//	col1 = s1[2];
//	col2 = s2[2];
//	cout << line1 << " " << line2 << " " << col1 << " " << col2; 
//	return 0;
//} 
#include<cstdio>
#include<iostream>
using namespace std;

string c1, s1, c2, s2; 

int main(){
	freopen("travel.in","r", stdin);
	freopen("travel.ans", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << "0000" << "\n";
		return 0;
	}
	cout << "1";
	if (s1[0] != s2[0] || s1[1] != s2[1]){
		cout << "000";
		return 0;
	}
	cout << "1";
	if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
		cout << "11";
		return 0; 
	}
	if (s1[2] != 'D' && s1[2] != 'F' && s2[2] != 'D' && s2[2] != 'F'){
		cout << "1";
		if ((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' || s2[2] == 'A')) cout << "0";
		else cout << "1";
	}
	else cout << "00";
	return 0;
}
