#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;//小R车厢号,小R座位号,小X车厢号,小X座位号
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	int a1,b1;
	a1=s1[0]-'0';
	b1=s1[1]-'0';
	int a2,b2;
	a2=s2[0]-'0';
	b2=s2[1]-'0';
	int sum1=a1*10+b1,sum2=a2*10+b2;
	if(sum1==sum2){
		cout<<"1";
	}
	else {
		cout<<"000";
		return 0;
	}
	if(s1[2]>'C'&&s2[2]>'C'||s1[2]<'D'&&s2[2]<'D'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0; 
	}
	if(s1[2]>'C'&&s2[2]>'C'){
		cout<<"1";
		return 0;
	}else if(s1[2]=='B'||s2[2]=='B'){
		cout<<"1";
		return 0;
	}else {
		cout<<"0";
		return 0;
	}
	return 0;
}
