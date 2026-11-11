#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ss1,ss2;
int f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) f1=1;
	else{
		cout<<"0000"; 
		return 0;
	}
	ss1=(s1[0]-'0')*10+(s1[1]-'0');
	ss2=(s2[0]-'0')*10+(s2[1]-'0');
	if(ss1==ss2) f2=1;
	else{
		cout<<1000;
		return 0;
	}
	if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
		f3=1;
	}
	else{
		cout<<1100;
		return 0;
	}
	if(s1[2]==s2[2]-1||s1[2]==s2[2]+1) f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
