#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	char s1,s2;
	cin>>a1>>a2>>b1>>b2;
	int flag=1;
	if(a1==b1) cout<<"1";
	else 
	{
		cout<<"0";
		flag=0;
	}
	int a=0,b=0;
	for(int i=0;i<a2.size();i++)
	{
		if(a2[i]>='0'&&a2[i]<='9') 
		{
			a*=10;
			a+=a2[i]-'0';
		}
		else 
		{
			s1=a2[i];
			
		}
	}
	for(int i=0;i<b2.size();i++)
	{
		if(b2[i]>='0'&&b2[i]<='9') 
		{
			b*=10;
			b+=b2[i]-'0';
		}
		else 
		{
			s2=b2[i];
			break;
		}
	}
	if(a==b&&flag==1) cout<<"1";
	else 
	{
		cout<<"0";
		flag=0;
	}
	if(a==b&&flag==1){
		if((s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C')) cout<<"1";
		else if((s1=='D'||s1=='E')&&(s2=='D'||s2=='E')) cout<<"1";
		else 
		{
			cout<<"0";
			flag=0;
		}
	}
	else 
	{
		cout<<"0";
		flag=0;
	}
	if(flag==1){
		if((s1=='A'&&s1=='B')||(s1=='B'&&s1=='C')||(s1=='D'&&s1=='E'))
		{
			cout<<"1";
		}
		else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
