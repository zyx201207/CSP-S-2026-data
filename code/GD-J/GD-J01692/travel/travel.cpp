#include <bits/stdc++.h>
using namespace std;
int x,y;
string xxx,yyy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x >> xxx >> y >> yyy;
	if( x != y ){
		cout << "0000";
		return 0;
	}
	else cout << 1;
	if( xxx[0] == yyy[0] && xxx[1] == yyy[1] ) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if( xxx[2] == 'A' ){
		if( yyy[2] == 'B' || yyy[2] == 'C' ) cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	else if( xxx[2] == 'B' ){
		if( yyy[2] == 'A' || yyy[2] == 'C' ) cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	else if( xxx[2] == 'C' ){
		if( yyy[2] == 'B' || yyy[2] == 'A' ) cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	else if( xxx[2] == 'D' ){
		if( yyy[2] == 'F' ) cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	else if( xxx[2] == 'F' ){
		if( yyy[2] == 'D' ) cout << 1;
		else{
			cout << "00";
			return 0;
		}
	}
	if( xxx[2] == 'A' ){
		if( yyy[2] == 'B' ) cout << 1;
		else{
			cout << 0;
		}
		return 0;
	}
	else if( xxx[2] == 'B' ){
		if( yyy[2] == 'A' || yyy[2] == 'C' ) cout << 1;
		else{
			cout << 0;
		}
		return 0;
	}
	else if( xxx[2] == 'C' ){
		if( yyy[2] == 'B' ) cout << 1;
		else{
			cout << 0;
		}
		return 0;
	}
	else if( xxx[2] == 'D' ){
		if( yyy[2] == 'F' ) cout << 1;
		else{
			cout << 0;
		}
		return 0;
	}
	else if( xxx[2] == 'F' ){
		if( yyy[2] == 'D' ) cout << 1;
		else{
			cout << 0;
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
