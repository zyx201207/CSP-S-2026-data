#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s2,c,c2;
	cin>>s>>s2>>c>>c2;
	if(s==c)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	int t=s2[0]+s2[1],t2=c2[0]+c2[1];
	if(s==c&&t==t2)
	{
		cout<<1;
	}
	else{
		cout<<0;	
	}
	if(s==c&&t==t2&&(((s2[2]=='D'||s2[2]=='F')&&(c2[2]=='D'||c2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(c2[2]=='C'||c2[2]=='B'||c2[2]=='C'))))
	{
		cout<<1;
	}
	else{
		cout<<0;	
	}
	if(s==c&&t==t2&&(((s2[2]=='D'||s2[2]=='F')&&(c2[2]=='D'||c2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(c2[2]=='C'||c2[2]=='B'||c2[2]=='C')))&&abs(s2[2]-c2[2])==1)
	{
		cout<<1;
	}
	else{
		cout<<0;	
	}

}
