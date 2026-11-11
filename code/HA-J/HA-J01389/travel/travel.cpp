#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string pai1;
		pai1=s1[0]+s1[1];
		string pai2;
		pai2=s2[0]+s2[1];
		if(pai1==pai2){
			cout<<'1';
			char num1;
			num1=s1[2];
			char num2;
			num2=s2[2];
			if((num1=='C'&&num2=='D')||(num1=='D'&&num2=='C')||(num1=='B'&&num2=='D')||(num1=='B'&&num2=='F')||(num1=='A'&&num2=='D')||(num1=='A'&&num2=='F')||(num1=='C'&&num2=='F')){
				cout<<"00";
			}else{
				cout<<'1';
				if((num1=='C'&&num2=='A')||(num1=='A'&&num2=='C')){
					cout<<'0';
				}else{
					cout<<'1';
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
