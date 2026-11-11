#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1 , s1 , c2 , s2;
	bool c = 1;
	cin >> c1 >> s1 >> c2 >> s2;
	if ( s2[2] == 'F' )
		s2[2] = 'E';
	if ( s1[2] == 'F' )
		s1[2] = 'E';
	c = c && ( c1 == c2 );
	cout << (int)c;
	c = c && ( s1.substr(0,2) == s2.substr(0,2) );
	cout << (int)c;
	c = c && ( ( s1[2] < 'D' && s2[2] < 'D' ) || ( s1[2] > 'C' && s2[2] > 'C' ) );
	cout << (int)c;
	c = c && ( s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1 );
	cout << (int)c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
