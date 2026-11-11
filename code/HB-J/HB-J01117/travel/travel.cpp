#include <bits/stdc++.h>
using namespace std;

//constants
const int N = 1e6 + 7;

//vars
int n;
int c1,c2;
string s1, s2;

bool check1(char ca,char cb){
	if((ca == 'A' || ca == 'B' || ca == 'C') && (cb == 'A' || cb == 'B' || cb == 'C')){
		return true;
	}
	if((ca == 'E' || ca == 'F') && (cb == 'A' || cb == 'B' || cb == 'C')){
		return true;
	}
	return false;
}

bool check2(char ca, char cb){
	if(ca < cb)swap(ca, cb);
	if((ca - cb == 1) && ca != 'E')return true;
	else return false;
}

//main
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	cin.tie(0),ios::sync_with_stdio(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	else cout << 1;
	
	if((s1[0] == s2[0]) && (s1[1] == s2[1])){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	
	if(check1(s1[2],s2[2])){
		cout << 1; 
	}else{
		 cout <<"00";
		 return 0;
	 }
	 
	 if(check2(s1[2], s2[2])){
		 cout << 1;
	 }
	 else cout << 0;
	
	return 0;
}
