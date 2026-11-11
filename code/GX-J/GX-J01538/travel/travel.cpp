#include<bits/stdc++.h>
using namespace std;
int a ;
char b[12] ;
int c ;
char d[12] ;
int blen ;
int dlen ;
bool fst = 0 ;
bool snd = 0 ;
bool trd = 0 ;
bool love = 0 ;
void shuru(){
	cin >> a ;
	cin >> b ;
	cin >> c ; 
	cin >> d ;
}
bool pai(){
	int wo = 0 ;
	int qwq = b[0] - '0' ;
	int jie = b[1] - '0' ;
	wo = qwq * 10 + jie * 1 ;
	int yao = 0 ;
	char chi = d[0] - '0' ;
	char fan = d[1] - '0' ;
	yao = chi * 10 + fan * 1 ;
	if( fst != 1 ){
		return 0 ;
	}
	if( wo == yao ){
		return 1 ;
	}else{
		return 0 ;
	}
}
bool panduan_1(){
	if( b[2] == 'A' or b[2] == 'B' or b[2] == 'C' ){
		if( d[2] == 'A' or d[2] == 'B' or d[2] == 'c' ){
			return 1 ;
		}
	}
	if( d[2] == 'A' or d[2] == 'B' or d[2] == 'C' ){
		if( b[2] == 'A' or b[2] == 'B' or b[2] == 'c' ){
			return 1 ;
		}
	}
	if( b[2] == 'D' or b[2] == 'F' ){
		if( d[2] == 'D' or d[2] == 'F' ){
			return 1 ;
		}
	}
	if( d[2] == 'D' or d[2] == 'F' ){
		if( b[2] == 'D' or b[2] == 'F' ){
			return 1 ;
		}
	}	
	return 0 ;
}
bool xianglin(){
	if( love != 1 ){
		return 0 ;
	}
	if( trd != 1 ){
		return 0 ;
	}
	if( b[2] == 'D' or b[2] == 'F' ){
		if( d[2] == 'D' or d[2] == 'F' ){
			return 1 ;
		}
	}
	if( b[2] + 1 == d[2] or b[2] - 1 == d[2] ){
		return 1 ;
	}
	if( d[2] + 1 == b[2] or d[2] - 1 == b[2] ){
		return 1 ;
	}
	return 0 ;
} 
void jisuan(){
	if( a == c ){
		fst = true ;
		cout << "1" ;
	}else{
		cout << "0" ;
	}
	if( fst == true ){
   		if( pai() == 1 ) {
			snd = true ;
			cout << "1" ;
			love = true ;
		}
	}else{
		cout << "0" ;
	}
	if( snd == true and panduan_1() == true ){
		trd = true ;
		cout << "1" ;
	}else{
		cout << "0" ;
	}
	if( xianglin() == true ){
		cout << "1" ;
	}else{
		cout << "0" ;
	}
	cout << endl;
}
int main(){
	freopen( "travel.in" , "r" , stdin ) ;
	freopen( "travel.out" , "w" , stdout ) ;
	shuru() ; 
	jisuan() ;
	return 0 ;
}
