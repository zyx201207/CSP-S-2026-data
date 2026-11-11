#include <bits/stdc++.h>
using namespace std ;

int main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	int n , m ;
	char n1[10] , m1[10];
	cin >> n >> n1 >> m >> m1 ;
	if(n != m){
		cout << "0000" ;
	}else{
		cout << 1 ;
		if(n1[0] != m1[0] or n1[1] != m1[1]){
			cout << "000" ;
		}else{
			cout << 1 ;
			if((n1[2] == 'E' or n1[2] == 'D') &&(m1[2] == 'E' or m1[2] == 'D')){
				cout << 1 ;
				if(n1[2] - m1[2] == 1 or n1[2] - m1[2] == -1){
					cout << 1 ;
				}else{
					cout << 0 ;
				}
			}else if ((n1[2]=='C' or n1[2] == 'A' or n1[2] == 'B') && (m1[2]=='C' or m1[2] == 'A' or m1[2] == 'B')){
				cout << 1 ;
				if(n1[2] - m1[2] == 1 or n1[2] - m1[2] == -1){
					cout << 1 ;
				}else{
					cout << 0 ;
				}
			}else{
				cout << "00" ;
			}
		}
	}
	cout << endl ;
	return 0 ;
}
