#include<bits/stdc++.h>
using namespace std;

char c1[8] ;
char c2[8] ;
char s1[8] ;
char s2[8] ;

void jisuan() {
	if( c1[0] == c2[0] && c1[1] == c2[1] ) {
		cout << "1" ;
		if( s1[0] == s2[0] && s1[1] == s2[1] ) {
			cout << "1" ;
			
			long long nums1 = s1[2] - 'A' + 1 ;
			long long nums2 = s2[2] - 'A' + 1 ;
			if( nums1 <= 3 && nums2 <= 3 ) {
				cout << "1" ;
				if( nums1 + 1 == nums2 || nums1 - 1 == nums2 ) {
					cout << "1" ;
				} else {
					cout << "0" ;
				}
			} else if( nums1 >= 4 && nums2 >= 4 ) {
				cout << "1" ;
				if( nums1 + 1 == nums2 || nums1 - 1 == nums2 ) {
					cout << "1" ;
				} else {
					cout << "0" ;
				}
			} else {
				cout << "00" ;
			}
			
		} else {
			cout << "000" ;
		}
	} else {
		cout << "0000" ;
	}
	
}

int main() {
	freopen( "travel.in", "r", stdin ) ;
	freopen( "travel.out", "w", stdout ) ;
	
	cin >> c1 >> s1 >> c2 >> s2 ;
	
	jisuan() ;
	return 0 ;
}
