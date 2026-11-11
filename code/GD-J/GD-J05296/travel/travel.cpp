#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string a1, a2, b1, b2;
bool zaiabc(char a){
	if(a == 'A' || a == 'B' || a == 'C') return true;
	return false;
}
bool xianglin(char a, char b){
	if(a == 'A' && b == 'B') return true;
	if(a == 'B' && b == 'C') return true;
	if(a == 'D' && b == 'F') return true;
	return false;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 != b1){
		cout << "0000";
		return 0;
	}
	if(a2[1] != b2[1]){
		cout << "1000";
		return 0;
	}
	if(zaiabc(a2[2]) != zaiabc(b2[2])){
		cout << "1100";
		return 0;
	}
	if(!xianglin(a2[2], b2[2])){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
