#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<"1";
		if(b1[0]==b2[0]&&b1[1]==b2[1]){
			cout<<"1";
			if(b1[2]>='D'&&b2[2]>='D'){
				cout<<"11";
			}else{
				if(b1[2]<='C'&&b2[2]<='C'){
					cout<<"1";
					if(b1[2]=='B'||b2[2]=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
					return 0;
				}
				
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";

	}
	return 0;
} 
