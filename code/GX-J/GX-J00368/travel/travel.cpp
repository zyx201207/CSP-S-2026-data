#include<bits/stdc++.h>
using namespace std;

string a1,a2,b1,b2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a1>>a2>>b1>>b2;
	
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	
	int a=0,b=0;
	for(int i=0;i<=1;i++)
	{
		a=a*10+a2[i]-'0';
		b=b*10+b2[i]-'0';
	}
	
	if(a!=b)
	{
		cout<<"1000";
		return 0;
	}
	
	
	a=a2[2]-'A';
	b=b2[2]-'A';
	
	if(a<3 && b<3)
	{
		if(a-b==1 || a-b==-1)
			cout<<"1111";
		else
			cout<<"1110";
	}
	else if(a>2 && b>2)
		cout<<"1111";
	else 
		cout<<"1100";
	return 0;
}
