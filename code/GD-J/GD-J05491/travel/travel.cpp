#include<bits/stdc++.h>
using namespace std ;

int main(){
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "W" , stdout) ;
	
	
	int c1 , c3 ;
	char c2[5] = {} , c4[5] = {} ;
	cin >> c1 >> c2 >> c3 >> c4 ;
	
	if(c1 == c3){
		cout << "1" ;
		
		if(c2[0] == c4[0] && c2[1] == c4[1]){
			cout << "1" ;
			if((c2[0] == c4[0] && c2[1] == c4[1]) && ((c2[2] == 'C' && c4[2] == 'D') || (c2[2] == 'D' && c4[2] == 'C'))){
				cout << "00" ;
			}else{
				cout << "1" ;
			
				if(int(c2[2]) + 1 == int(c4[2]) || int(c2[2]) - 1 == int(c4[2])) {
					cout << "1" ;
				} else{
					cout << "0" ;
				}//相邻
			 
			}//同排 ， 同侧
		}else{
			cout << "000" ;
		}//同排  
		
	}else{
		cout << "0000" ;
	}//同一车厢
	
	return 0 ;
} //02 01A 02 01B 
