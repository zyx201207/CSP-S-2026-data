#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;		
bool in1(char a,char b){
	return (a==b)||((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='A')||(a=='C'&&b=='B'))||((a=='D'&&b=='E')||(a=='E'&&b=='D'));
}		
bool in2(char a,char b){
	return (abs(a-b)==1);
}						
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		string aa1;
		aa1+=a2[0];
		aa1+=a2[1];
		char aa2=a2[2];
		string bb1;
		bb1+=b2[0];
		bb1+=b2[1];
		char bb2=b2[2];
		if(aa1==bb1){
			cout<<"1";
			if(in1(aa2,bb2)){
				cout<<"1";
				if(in2(aa2,bb2)){
					cout<<"1";
				}else{
					cout<<"0";
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
