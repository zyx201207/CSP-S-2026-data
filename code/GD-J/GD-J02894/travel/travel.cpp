#include<bits/stdc++.h>
using namespace std;
string  c1 , s1 , c2 , s2;
int cnt = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen ( "travel.in" , "r" , stdin );
	freopen ( "travel.out" , "w" , stdout );
	cin >> c1 >> s1 >> c2 >> s2;
	if( c1 == c2 ){
		cout << "1";
		for( int i = 0 ; i < 2 ; i++ ) if ( s1[i] == s2[i] ) cnt++;
		if( cnt == 2 ){
			cout << "1";
			if(( s1[2] <= 'C' && s1[2] >= 'A' && s2[2] <= 'C' && s2[2] >= 'A' ) || ( s1[2] <= 'F' && s1[2] >= 'D' && s2[2] <= 'F' && s2[2] >= 'D' )){
				cout << "1";
				if( s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1 ) cout << "1";
				else cout << "0";
			}
			else for( int i = 1 ; i <= 2 ; i++ ) cout << "0";
		}
		else for( int i = 1 ; i <= 3 ; i++ ) cout << "0";
	}
	else for( int i = 1 ; i <= 4 ; i++ ) cout << "0";
	return 0;
}
