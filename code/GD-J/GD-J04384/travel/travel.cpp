#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string sx,sr;
	int len = sx.size();
	cin >> cr >> sr>> cx >> sx;
	if(cr == cx){
		cout << "1";
		if(sx[0] != sr[0]){
			cout <<"000"; 
		}else{
			if(sx[1]!=sr[1]){
				cout << "000";
			}else{
				cout << "1";
				if(sx[2] >='A'&&sx[2]<='C'&&sr[2]>='A'&&sr[2]<='C'){
					if(sx[2]-'A' == sr[2]-'A'+1||sx[2]-'A' == sr[2]-'A'+2||sr[2]-'A' == sx[2]-'A'+1||sr[2]-'A' == sx[2]-'A'+2){
						cout << "1";
						if(sx[2]-'A' == sr[2]-'A'+1||sr[2]-'A' == sx[2]-'A'+1){
							cout << "1";
						}else{
							cout << "0";
						}
					}else{
						cout << "00";
					}
				}else if(sx[2] >='D'&&sx[2]<='F'&&sr[2]>='D'&&sr[2]<='F'&&sx[2] !='E'&&sr[2]!='E'){
					if(sx[2]-'A' == sr[2]-'A'+2||sr[2]-'A' == sx[2]-'A'+2){
						cout << "11";
					}else{
						cout << "00";
					}
				}else{
					cout << "00";
				}
			}
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
