#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s,str;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s>>c2>>str;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		if(s[0]==str[0]&&s[1]==str[1]){
			cout<<"1";
			if(s[2]<='C'&&str[2]<='C'){
				cout<<"1";
				if(s[2]+1==str[2]||s[2]-1==str[2]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(s[2]>'C'&&str[2]>'C'){
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
	return 0;
} 
