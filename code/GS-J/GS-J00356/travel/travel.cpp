#include <bits/stdc++.h>
using namespace std;
string cx1,cx2,seat1,seat2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>seat1>>cx2>>seat2;
	if(cx1==cx2){
		cout<<'1';
		if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
			cout<<'1';
			if((seat1[2]>='A'&&seat1[2]<='C'&&seat2[2]>='A'&&seat2[2]<='C')||(seat1[2]>='D'&&seat1[2]<='F'&&seat2[2]>='D'&&seat2[2]<='F')){
				cout<<'1';
				if((seat1[2]=='A'&&seat2[2]=='B')||(seat1[2]=='B'&&seat2[2]=='C')||(seat1[2]=='D'&&seat2[2]=='F')||(seat2[2]=='A'&&seat1[2]=='B')||(seat2[2]=='B'&&seat1[2]=='C')||(seat2[2]=='D'&&seat1[2]=='F')){
					cout<<'1';
				}else{
					cout<<'0';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
