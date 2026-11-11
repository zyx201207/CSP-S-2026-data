#include<bits/stdc++.h>
using namespace std;
string s1 , s2 ;
string s3 , s4 ;
int f1 , f2 , f3 , f4 ;
map<char , int> m ;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	m['A'] = 1 ;
	m['B'] = 2 ;
	m['C'] = 3 ;
	m['D'] = 4 ;
	m['F'] = 5 ;
	cin >> s1 >> s2 >> s3 >> s4 ;
	if((s1[0] == s3[0]) && (s1[1] == s3[1])){
		cout << 1 ;
	}else{
		cout << "0000" ;
		return 0;
	}
	if((s2[0] == s4[0]) && (s2[1] == s4[1])){
		cout << 1 ;
	}else{
		cout << "000" ;
		return 0 ;
	}
	if((m[s2[2]] <= 3 && m[s4[2]] <= 3)|| (m[s2[2]] >= 4 && m[s4[2]] >= 4)){
		cout << 1 ;
	}else{
		cout << "00";
		return 0 ;
	}
	int t1 = m[s2[2]] , t2 = m[s4[2]];
	if( abs(t1 - t2)== 1){
		cout << 1 ;
	}else{
		cout << 0 ;
	}
	return 0 ;
}


