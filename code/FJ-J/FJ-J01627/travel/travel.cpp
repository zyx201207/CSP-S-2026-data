#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int is1=0,is2=0;
	char num1=0,num2=0;
	for(char i:s1){
		if(i<='9'&&i>='0') is1=is1*10+i-'0';
		else num1=i;
	}
	for(char i:s2){
		if(i<='9'&&i>='0') is2=is2*10+i-'0';
		else num2=i;
	}
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(is1==is2) cout<<"1";
	else{
		cout<<"000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	bool a=0,b=0,c=0,d=0,f=0;
	if((num1=='A')||(num2=='A')) a=1;
	if((num1=='B')||(num2=='B')) b=1;
	if((num1=='C')||(num2=='C')) c=1;
	if((num1=='D')||(num2=='D')) d=1;
	if((num1=='F')||(num2=='F')) f=1;
	if((a&&b)||(b&&c)||(a&&c)||(d&&f)) cout<<"1";
	else{
		cout<<"00";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if((a&&b)||(b&&c)||(d&&f)) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
	/*
	111 111 111
	1   1   1
	111 111 111
	1 1 1 1 1 1
	111 111 111
	*/
}
