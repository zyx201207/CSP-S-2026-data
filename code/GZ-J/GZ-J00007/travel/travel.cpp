//GZ-J00007,裘滨溪,贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int work(char c){
	if(c=='A'){
		return 1;
	}
	if(c=='B'){
		return 2;
	}
	if(c=='C'){
		return 3;
	}
	if(c=='D'){
		return 5;
	}
	if(c=='F'){
		return 6;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<"1";
		if(b1[0]==b2[0] && b1[1]==b2[1]){
			cout<<"1";
			int num1=work(b1[2]),num2=work(b2[2]);
			if((num1<4 && num2<4) || (num1>4 && num2>4)){
				cout<<"1";
				if(abs(num1-num2)==1){
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
