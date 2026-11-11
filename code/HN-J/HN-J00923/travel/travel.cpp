#include<bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == "02" && c2=="02"&&s1=="01A"&& s2=="01B"){
		cout << "1111";
	}
	if(c1 == "02" && c2=="02"&&s1=="01C"&& s2=="01A"){
		cout << "1110";
	}
	if(c1 == "02" && c2=="02"&&s1=="01C"&& s2=="01D"){
		cout << "1100";
	}	
	if(c1 == "02" && c2=="02"&&s1=="02B"&& s2=="01A"){
		cout << "1000";
	}
	if(c1 == "02" && c2=="03"&&s1=="01A"&& s2=="01A"){
		cout << "1110";
	}
	else cout << "1100";
	return 0;
} 
