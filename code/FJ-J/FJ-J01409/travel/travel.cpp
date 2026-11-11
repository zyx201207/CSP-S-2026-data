#include<iostream>
using namespace std;

string t[5];

int main() 
{
	fopen("travel.in","r");
	fopen("travel.out","w");
	for(int i=1;i<=4;i++)
	{
		cin>>t[i];
	}
	if(t[1]==t[3])
		cout<<"1";	
	else
	{	
		cout<<"0000";
		return 0;
	}
		
	int a=0,b=0;
	for(int i=0;i<2;i++)
	{
		a=a*10+(t[2][i]-'0');
		b=b*10+(t[4][i]-'0');
	}
	if(a==b)
		cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if((t[2][2]>='A'&&t[2][2]<='C'&&t[4][2]>='A'&&t[4][2]<='C')||(t[2][2]>='D'&&t[4][2]>='D'))
		cout<<"1";
	else
	{
		cout<<"00";
		return 0;	
	}
	if(t[2][2]+1==t[4][2]||t[2][2]-1==t[4][2])
		cout<<"1";
	else
	{
		cout<<"0";
	}
	return 0;
}
