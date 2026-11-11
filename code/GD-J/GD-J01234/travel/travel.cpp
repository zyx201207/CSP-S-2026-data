#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string a , b , c , d;
	cin >> a >> b >> c >> d;
	if(a == c){
		int flag = 0;
		for(int i = 0 ; i < 2 ; i ++){
			if(b[i] != d[i]){
				flag = 1;
			}
		}
		if(flag == 0){
			char m = b[2];
			char n = d[2];
			if((m >= 'A' && m <= 'C' && n > 'C' && n <= 'F') || (n >= 'A' && n <= 'C' && m > 'C' && m <= 'F')){
				cout << "1100";
			}else{
				if((m == 'A' && n == 'C') || (n == 'A' && m == 'C')){
					cout << "1110";
				}else{
					cout << "1111";
				}
			}
		}else{
			cout << "1000";
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
