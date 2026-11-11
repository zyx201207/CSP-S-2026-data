#include <bits/stdc++.h>
using namespace std;

bool inrange(char l , char r , char v) {return (v >= l) && (v <= r);}

int main(){
	
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << "1";
	if (s1.substr(0,2) != s2.substr(0,2)){
		cout << "000";
		return 0;
	}
	cout << "1";
	
	if (inrange('A','C',s1[2]) != inrange('A','C',s2[2])){
		cout << "00";
		return 0;
	}
	cout << "1";
	if ( abs( int(s1[2]) - int(s2[2]) )  == 1 ){
		cout << "1";
	}
	else{
		cout << "0";
	}
	
	return 0;
}
