#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s3>>s2>>s4;
	int f1,f2;
	if(s3[2]=='A'||s3[2]=='B'||s3[2]=='C')f1=1;
	else f1=0;
	if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')f2=1;
	else f2=0;
	if(s1==s2)cout<<1;
	else{cout<<"0000";return 0;}
	if(s3[0]==s4[0]&&s3[1]==s4[1])cout<<1;
	else{cout<<"000";return 0;}
	if(f1==f2)cout<<1;
	else {cout<<"00";return 0;}
	if(f1==f2)
	{
		if((f1==1&&(s3[2]=='B'||s4[2]=='B')))cout<<1;
		
		else if(f1==0)cout<<1;
		else cout<<0;
	}
	else cout<<0;
}
