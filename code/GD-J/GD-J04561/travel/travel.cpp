#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,a; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) a='1';
	else{
		a="0000";
		cout<<a;
		return 0;
	} 
	if(s1[0]==s2[0]&&s1[1]==s2[1]) a=a+'1';
	else{
		a=a+'0'+'0'+'0';
		cout<<a;
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C') a=a+'1';
	else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F') a=a+'1';
	else{
		a=a+'0'+'0';
		cout<<a;
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B') a=a+'1';
	else if(s1[2]=='B'&&s2[2]=='A') a=a+'1';
	else if(s1[2]=='B'&&s2[2]=='C') a=a+'1';
	else if(s1[2]=='B'&&s2[2]=='C') a=a+'1';
	else if(s1[2]=='E'&&s2[2]=='F') a=a+'1';
	else if(s1[2]=='F'&&s2[2]=='E') a=a+'1';
	else a=a+'0';
	cout<<a;
	return 0; 
} 
