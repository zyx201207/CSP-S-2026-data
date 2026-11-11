#include<bits/stdc++.h>
using namespace std;
string s1 , s2 , s3 , s4;
int main(){
	freopen( "travel.in" , "r" , stdin );
	freopen( "travel.out" , "w" , stdout );
	cin >> s1 >> s2 >> s3 >> s4;
	int len1 = s1.size() , len2 = s3.size(); 
	if( len1 == len2 ){
		for( int i = 0 ; i < len1 ; i++ ){
			if( s1[i] != s3[i] ){
				cout << "0000";
				return 0;
			}
		}
	}
	cout << 1;
	for( int i = 0 ; i < 2 ; i++ ){
		if( s2[i] != s4[i] ){
			cout << "000";
			return 0;
		}
	}
	cout << 1;
	if( ((s2[2] >= 'A' && s2[2] <= 'C') && (s4[2] >= 'A' && s4[2] <= 'C')) || ((s2[2] == 'D' || s2[2] == 'F') && (s4[2] == 'D' || s4[2] == 'F'))){
		cout << 1;
		int a = int(s2[2]) , b = int(s4[2]);
		if( (a == 65 && b == 66) || (a == 66 && ( b == 65 || b == 67 )) || (a ==67 && b == 66) || (a == 68 && b == 70) || (a == 70 && b == 68) ){
			cout << 1;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	else cout << 0 << 0;
	return 0;
} 
