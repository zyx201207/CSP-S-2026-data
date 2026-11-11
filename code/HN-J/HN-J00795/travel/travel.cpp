#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>a2>>b1>>b2;
	int f1=0,f2=0,f3=0,f4=0;
	if(a1==b1)f1=1;
	if(((a2[0]-'0')*10+(a2[1]-'0'))==((b2[0]-'0')*10+(b2[1]-'0'))&&f1==1)f2=1;
	if(a2[2]=='D'&&b2[2]=='F'&&f2==1)f3=1;
	if(a2[2]=='F'&&b2[2]=='D'&&f2==1)f3=1;
	if(a2[2]=='A'&&b2[2]=='B'&&f2==1)f3=1;
	if(a2[2]=='A'&&b2[2]=='C'&&f2==1)f3=1;
	if(a2[2]=='B'&&b2[2]=='A'&&f2==1)f3=1;
	if(a2[2]=='B'&&b2[2]=='C'&&f2==1)f3=1;
	if(a2[2]=='C'&&b2[2]=='A'&&f2==1)f3=1;
	if(a2[2]=='C'&&b2[2]=='B'&&f2==1)f3=1;
	
	if(a2[2]=='D'&&b2[2]=='F'&&f3==1)f4=1;
	if(a2[2]=='F'&&b2[2]=='D'&&f3==1)f4=1;
	if(a2[2]=='A'&&b2[2]=='B'&&f3==1)f4=1;
	if(a2[2]=='B'&&b2[2]=='A'&&f3==1)f4=1;
	if(a2[2]=='B'&&b2[2]=='C'&&f3==1)f4=1;
	if(a2[2]=='C'&&b2[2]=='B'&&f3==1)f4=1;
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
