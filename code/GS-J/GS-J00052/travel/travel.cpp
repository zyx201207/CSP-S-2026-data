#include <iostream>
using namespace std;

main(){
	string c1[3],s1[4],c2[3],s2[4];
	cin >> c1[1] >> c1[2];
	cin >> s1[1] >> s1[2] >> s1[3];
	cin >> c2[1] >> c2[2];
	cin >> s2[1] >> s2[2] >> s2[3];
	if (c1[1]==c2[1] && c1[2]==c2[2]){
		cout << "1";		
	}
	else {
		cout << "0";
	}
	if (s1[1]==s2[1] && s1[2]==s2[2]){
		cout << "1";		
	}
	else {
		cout << "0";
	}
	int a=0,b=0;
	if (s1[3]=="A") a=1;
	else if(s1[3]=="B") a=2;
	else if(s1[3]=="C") a=3;
	else if(s1[3]=="D") a=4;
	else if(s1[3]=="F") a=5;
	if (s2[3]=="A") b=1;
	else if(s2[3]=="B") b=2;
	else if(s2[3]=="C") b=3;
	else if(s2[3]=="D") b=4;
	else if(s2[3]=="F") b=5;
	if (a<=3 && b<=3){
		cout << "1";
	}
	else if(a>=4 && b>=4){
		cout << "1";
	}
	else {
		cout << "0";
	}
	if (a==b+1 || a==b-1){
		cout << "1";		
	}
	else {
		cout << "0";
	}
	return 0;
}


