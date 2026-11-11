#include<bits/stdc++.h>
using namespace std;

#define gc getchar

typedef long long ll;
const int max_n = 5e5 + 7;
int c , t;

inline ll re(){
	ll num = 0 , f = 1 ; char x = gc();
	while( !isdigit( x ) && x != '-' ) x = gc();
	if( x == '-' ) f = -1 , x = gc();
	while( isdigit(x) ) num = num * 10 + x - '0' , x = gc();
	return num * f; 
}



int main(){
	
	freopen( "hub.in" , "r" , stdin );
	freopen( "hub.out" , "w" , stdout );
	
	c = re() , t = re();
	for( int i = 1 ; i <= t ; i++ ) printf( "%d" , 1 );
}
/*
Oct31==Dec25?
*/
