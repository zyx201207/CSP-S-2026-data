#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(char a , char b){
	if((a == 'F' && b == 'D') || (a == 'D' && b == 'F') || (a == 'C' && b == 'B') || (a == 'C' && b == 'A') ||(a == 'B' && b == 'C') ||(a == 'B' && b == 'A') ||(a == 'A' && b == 'B') ||(a == 'A' && b == 'C')){
	    return true;
	}else return false;
}

bool check1(char a , char b){
	if((a == 'F' && b == 'D') || (a == 'D' && b == 'F') || (a == 'C' && b == 'B') || (a == 'B' && b == 'C') || (a == 'A' && b == 'B') || (a == 'B' && b == 'A')){
		return true;
	}else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2){
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	
	ll r = 0;
	r += (s1[0] - '0');
	r += (s1[1] - '0');
	
	ll x = 0;
	x += (s2[0] - '0');
	x += (s2[1] - '0');
	
	if(x == r){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	
	
	char r1;
	r1 = s1[2];
	
	char x1;
	x1 = s2[2];
    
	if(check(x1 , r1)){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	
	if(check1(x1 , r1)){
		cout << "1";
	}else cout << "0";
	return 0;
}
