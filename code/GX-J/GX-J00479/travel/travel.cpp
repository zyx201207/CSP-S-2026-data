#include <bits/stdc++.h>
using namespace std;
int main() {
	
	freopen( "travel.in", "r", stdin );
	freopen( "travel.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	long long a1,b1 ;
	string a2,b2 ;
	cin >> a1 >> a2 >> b1 >> b2 ;
	if ( a1==b1 ) {
		cout<< 1 ;
	}else {
		cout<< 0 ;
	}
	
	if ( a1==b1 && a2.substr(0,2)==b2.substr(0,2) ) {
		cout<< 1 ;
	}else {
		cout<< 0 ;
	}
	
	if ( a1==b1 && a2.substr(0,2)==b2.substr(0,2) && ((a2.substr(2,1)>="D" && b2.substr(2,1)>="D") || (a2.substr(2,1)<="C" && b2.substr(2,1)<="C")) ) {
		cout<< 1 ;
		string a=a2.substr(2,1) ;
		string b=b2.substr(2,1) ;
		if ( ((a=="A" && b=="B")||(a=="B" && b=="A")) || ((a=="B" && b=="C")||(a=="C" && b=="B")) || ((a=="D" && b=="F")||(a=="F" && b=="D")) ) {
			cout<< 1 ;
		}else {
			cout<< 0 ;
		}
	}else {
		cout<< 0 ;
		cout<< 0 ;
	}
	
 return 0;
 }
