#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2,s3,s4;
	cin >> s1 >> s2 >> c1 >> c2;
	if(s1 == c1){
		cout << 1;
		int a = (s2[1] - '0') * 10 + (s2[2] - '0');
		int b = (c2[1] - '0') * 10 + (c2[2] - '0');
		if(a == b){
			cout << 1;
			
			if(s2[3] == 'A') {
				if(c2[3] == 'B'){
					cout << "11";
					return 0;
				}
				if(c2[3] == 'C'){
					cout << "10";
					return 0;
				}
				if(c2[3] == 'D'){
					cout << "00";
					return 0;
				}if(c2[3] == 'F'){
					cout << "00";
					return 0;
				}
			}
			
			if(s2[3] == 'B') {
				if(c2[3] == 'A'){
					cout << "11";
					return 0;
				}
				if(c2[3] == 'C'){
					cout << "11";
					return 0;
				}
				if(c2[3] == 'D'){
					cout << "00";
					return 0;
				}if(c2[3] == 'F'){
					cout << "00";
					return 0;
				}
			}
			
			if(s2[3] == 'C') {
				if(c2[3] == 'B'){
					cout << "11";
					return 0;
				}
				if(c2[3] == 'A'){
					cout << "10";
					return 0;
				}
				if(c2[3] == 'D'){
					cout << "00";
					return 0;
				}if(c2[3] == 'F'){
					cout << "00";
					return 0;
				}
			}
			
			if(s2[3] == 'D') {
				if(c2[3] == 'F'){
					cout << "11";
					return 0;
				}
				if(c2[3] == 'C'){
					cout << "00";
					return 0;
				}
				if(c2[3] == 'A'){
					cout << "00";
					return 0;
				}if(c2[3] == 'B'){
					cout << "00";
					return 0;
				}
			}
			
			if(s2[3] == 'F') {
				if(c2[3] == 'D'){
					cout << "11";
					return 0;
				}
				if(c2[3] == 'C'){
					cout << "00";
					return 0;
				}
				if(c2[3] == 'A'){
					cout << "00";
					return 0;
				}if(c2[3] == 'B'){
					cout << "00";
					return 0;
				}
			}
			
			
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}
