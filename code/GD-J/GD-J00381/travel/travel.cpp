#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int num,num1,c; 
	string a[5]={"A","B","C","D","E"};
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
}
	if(s1[2]=='A') num =0;
	if(s1[2]=='B') num =1;
	if(s1[2]=='C') num =2;
	if(s1[2]=='D') num =3;
	if(s1[2]=='E')num =4;
	if(s2[2]=='A')num1 =0;
	if(s2[2]=='B') num1 =1;
	if(s2[2]=='C') num1 =2;
	if(s2[2]=='D') num1 =3;
	if(s2[2]=='E')num1 =4;
	if((num==3&&num1==4)||(num==4&&num1==3)){
		cout<<"11";
		return 0;
	}
	else{
	   if(num==3||num==4||num1==3||num1==4)	{
	   	cout<<"00";
	   	return 0; 
	   }
	   int ans=num-num1;
	   if(ans==1||ans==-1){
	   	cout<<"11";
	   	return 0;
	   }
	   else{
	   	 
	   	cout<<"10";
	   }
	}

	return 0;
} 
