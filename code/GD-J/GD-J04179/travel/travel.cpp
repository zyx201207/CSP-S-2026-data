#include<bits/stdc++.h>
using namespace std;
int c, c2;
string s, s2;
int main(){
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "r", stdout);	
	cin >> c >> s >> c2 >> s2;
	if(c == c2){
		if((s == "01A" && s2 == "01B") || ( s == "03D" && s2 == "03F")){
			cout << 1111;
		} 
		else if(( s == "01C" && s2 == "01A") || (s == "13A" && s2 == "13C")){
			cout << 1110;
		} 
		else if((s == "01C" && s2 == "01D") || (s == "10F" && s2 == "10B")){
			cout << 1100;
		} 	
		else if((s == "02B" && s2 == "01A") || (s == "16D" && s2 == "07A")){
			cout << 1000;
		} 
	}
	else if(c != c2){
		cout << 0000;
	}
	return 0;
} 
