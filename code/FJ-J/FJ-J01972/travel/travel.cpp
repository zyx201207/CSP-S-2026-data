#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a1,a2,a3,a4;
char num1,num2;
bool flag1=false,flag2=false,flag3=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a3>>a4;
	if(a1==a3){
		cout<<1;flag1=true;
	} 
	else cout<<0;
	if(flag1&&a2[0]==a4[0]&&a2[1]==a4[1]){
		cout<<1;flag2=true;	
	} 
	else cout<<0;
	num1=a2[2];
	num2=a4[2];
	if(flag2&&((num1<='C'&&num2<='C')||(num1>'C'&&num2>'C'))){
		flag3=true;
		cout<<1;
	}
	else cout<<0;
	if(flag3&&(abs((int)(num1-num2))==1||(num1=='D'&&num2=='F')||(num2=='D'&&num1=='F'))) cout<<1;
	else cout<<0;
	return 0;
}
