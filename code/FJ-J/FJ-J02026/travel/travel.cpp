#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<"1";
			char r=sr[2],x=sx[2];
			if(r>='A'&&r<='C'&&x>='A'&&x<='C'){
				cout<<"1";
				if(abs(r-x)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(r>='D'&&r<='F'&&x>='D'&&x<='F'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
