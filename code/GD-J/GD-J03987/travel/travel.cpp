#include<bits/stdc++.h>
using namespace std;
string s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++){
		cin>>s[i];
	}
	if(s[0]==s[2]){
		if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]){
			if(s[1][2]>'C'&&s[3][2]>'C'){
				cout<<1111;
			}
			else if(s[1][2]<='C'&&s[3][2]<='C'){
				if(abs(int(s[1][2])-int(s[3][2]))==1){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else{
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
