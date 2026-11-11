#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int e = 0 , s = 0 ;
	string a ;
	for ( int i = 1 ; i <= 4 ; i ++ ){
		cin >> a [ i ] ;
	}
	if ( a [ 1 ] == a [ 3 ] ){
		e += 1 ;
	}
	for ( int i = 1 ; i <= 1 ; i ++ ){
	    if ( a [ 2 ] == a [ 4 ] ){
		    s = 0 ;
	    }
	    else {
		    s += 1 ;
	    }
    }
	for ( int i = 1 ; i <= 1 ; i ++ ){
	    if ( e > 0 ){
		    cout << "1" ;
	    }
	    else {
	    	cout << "0" ;
		}
    }
	for ( int j = 1 ; j <= 1 ; j ++ ){
	    if ( s == 0 ) {
	   		cout << "0" ;
		}
		else {
			cout << "1" ;
		}
    }
    for ( int i = 1 ; i <= 1 ; i ++ ){
	    if ( s == 0 ) {
	    		cout << "0" ;
			}
			else {
				cout << "1" ;
			}
    }
    cout << "0" ;
	return 0 ;
}
