#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1;
string c1,s1,c2,s2;
char _1,_2;     
int a=0,b=0; //ÅÅÊý
bool flag1,flag2,flag3;                               
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		flag1=1;
		cout<<1;
	}
	else cout<<0;
	if(flag1)
	{
	if(s1[0]=='0') a+=s1[1]-'0';
	else a+=10+s1[1]-'0';
	if(s2[0]=='0') b+=s2[1]-'0';
	else b+=10+s2[1]-'0';
	if(a==b) 
	{
		flag2=1;
		cout<<1;
	}
	else cout<<0;
	}
    else cout<<0;
	_1=s1[2];
	_2=s2[2];
	if(flag2)
	{
		if(_1=='A'&&(_2=='B'||_2=='C'))
	{
		cout<<1;
		flag3=1;
	} 
	else if(_1=='B'&&(_2=='A'||_2=='C'))
	{  
	    cout<<1;
		flag3=1;
	 } 
	else if(_1=='C'&&(_2=='A'||_2=='B'))
	 {  
	    cout<<1;
		flag3=1;
	 } 
	else if(_1=='D'&&_2=='F') 
	{  
	    cout<<1;
		flag3=1;
	 } 
	else if(_1=='F'&&_2=='D') 
	{  
	    cout<<1;
		flag3=1;
	} 
	else cout<<0;
	}
	else cout<<0;
	if(flag3)
	{
		if(_1=='A'&&_2=='B') cout<<1;
		else if(_1=='B'&&(_2=='A'||_2=='C')) cout<<1;
		else if(_1=='C'&&_2=='B') cout<<1;
		else if(_1=='D'&&_2=='F') cout<<1;
		else if(_1=='F'&&_2=='D') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
