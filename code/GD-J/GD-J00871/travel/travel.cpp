#include<iostream>
#include<string> 
using namespace std;
int getside(char c){
	if(c == 'A' || c == 'B' || c == 'C') return 0;
	else return 1;
}
bool isnext(char c1, char c2){
	if(c1 > c2) swap(c1,c2);
	if(c2 != 'D' && c2 - c1 == 1) return 1;
	if(c2 == 'F' && c1 == 'D') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool samec = c1 == c2;
	bool samel = s1.substr(0,2) == s2.substr(0,2);
	bool sames = getside(s1[2]) == getside(s2[2]);
	bool next = isnext(s1[2],s2[2]);
	cout << (int)(samec);
	cout << (int)(samec & samel);
	cout << (int)(samec & samel & sames);
	cout << (int)(samec & samel & sames & next);
	return 0;
}
