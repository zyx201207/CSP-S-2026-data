#include<bits/stdc++.h>
using namespace std;

string cr, sr, cx, sx;

int main(){
	
	freopen( "travel.in", "r", stdin );
	freopen( "travel.out", "w", stdout );
	
	cin >> cr >> sr >> cx >> sx;
	if( cr == cx ){
		cout << 1;
		if( sr[0] == sx[0] && sx[1] == sx[1] ){
			cout << 1;
			int r = 0, x = 0;
			for( int i = 0; i <= 2; i++ ){
				r += int( sr[i] );
				x += int( sx[i] );
			}
			if( ( ( sr[2] >= 'A' && sr[2] <= 'C' ) && ( sx[2] >= 'A' && sx[2] <= 'C' ) ) || ( ( sr[2] >= 'D' && sr[2] <= 'F' ) && ( sx[2] <= 'F' && sx[2] >= 'D' ) ) ){
				cout << 1;
			}else{
				cout << "0";
			}
	
			if( abs( r - x ) == 1 ){
				cout << 1;
			}else{
				cout << 0;
			}
		}else{
			cout << "000";
		}
	}else{	
		cout << "0000";
	}
	
	
	
	
	
	
	return 0;
} 
