#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen( "travel.in", "r", stdin );
	freopen( "travel.out", "w", stdout );
	string c1, s1, c2, s2;
	bool a,b,c,d;
	cin >> c1 >> s1 >> c2 >> s2;
	if( c1 == c2 ){
		a = true;
	}
	else{
		a = false;
	}
	if ( a && s1[0] == s2[0] && s1[1] == s2[1] ){
		b = true;
	}
	else{
		b = false;
	}
	if ( b && ( ( s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || ( s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F') ) ){
		c = true;
	}
	else{
		c = false;
	}
	if ( c && abs( (s1[2]-'A') - (s2[2]-'A') ) == 1 ){
		d = true;
	}
	else{
		d = false;
	}
	cout << a <<b << c << d << "\n";
	return 0;
}
