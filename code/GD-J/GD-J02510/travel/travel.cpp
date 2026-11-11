#include <bits/stdc++.h>
using namespace std;

bool check1(char cc, char dd){
	if(cc >= 'D' && cc <= 'F' && dd >= 'D' && dd <= 'F'){
		return true;
	}
	if(cc >= 'A' && cc <= 'C' && dd >= 'A' && dd <= 'C'){
		return true;
	}
	return false;
}

bool check2(char cc, char dd){
	if(cc == 'A' && dd == 'B') return true;
	if(cc == 'B' && dd == 'A') return true;
	if(cc == 'B' && dd == 'C') return true;
	if(cc == 'C' && dd == 'B') return true;
	if(cc == 'D' && dd == 'F') return true;
	if(cc == 'F' && dd == 'D') return true;
	else return false;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	
	string a = "", b = "";
	a = s1.substr(0, 2), b = s2.substr(0, 2);
//	cout << '\n' << a << ' ' << b << '\n';
	if(c1 == c2 && a == b){
		cout << 1;
	}else{
		cout << 0;
	}
	
	char c = s1[2], d = s2[2];
	if(c1 == c2 && a == b && check1(c, d)){
		cout << 1;
	}else{
		cout << 0;
	}
	
	if(c1 == c2 && a == b && check2(c, d)){
		cout << 1;
	}else{
		cout << 0;
	}
}

//Trick||Treat!
