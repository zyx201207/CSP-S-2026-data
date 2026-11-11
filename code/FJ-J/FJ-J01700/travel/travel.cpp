#include <bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int num1,num2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a1>>a2>>b1>>b2;
	if(a1!=b1){cout <<"0000";return 0;}
	cout <<1;
	num1=(a2[0]-'0')*10+a2[1]-'0';
	num2=(b2[0]-'0')*10+b2[1]-'0';
	c1=a2[2],c2=b2[2];
	if(num1!=num2){cout <<"000";return 0;}
	cout <<1;
	if(c1>='D'){
		if(c2<'D'){cout <<"00";return 0;}
	}
	else {
		if(c2>='D'){cout <<"00";return 0;}
	}
	cout <<1;
	if(abs(c1-c2)==1)cout <<1;
	else cout <<0;
}
