//GZ-J00135 观山湖区外国语实验中学（南校区） 安辉煌
#include <bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
string c1,c2;
int a[10]={};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2&&c1!="1"&&c1!="16"){
		a[1]=1;
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		a[2]=1;
	}
	else {
		cout<<"1000";
		return 0;
	}
	if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D')){
		a[3]=1;
	}
	else {
		cout<<"1100";
		return 0;
	}
	if(s1[3]==s2[3]+1||s1[3]==s2[3]-1){
		a[4]=1;
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
} 
