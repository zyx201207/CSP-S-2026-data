#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2;
	char s1[5],s2[5];
	cin >>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	int n1=(s1[1]-48)*10+(s1[2]-48),n2=(s2[1]-48)*10+(s2[2]-48);
	if(c1==c2){
		cout <<1;
		if(n1==n2){
			cout <<1;
			if(s1[3]<='C'){
				if(s2[3]<='C'){
					cout <<1;
					if(s1[3]=='B' || s2[3]=='B'){
						cout <<1;
					}else{
						cout <<0;
					}
				}else{
					cout <<"00";
				}
			}else{
				if(s2[3]>'C'){
					cout <<1;
				}else{
					cout <<0;
				}
				cout <<0;
			}
		}else{
			cout <<"000";
		}
	}else{
		cout <<"0000";
	}
	return 0;
}