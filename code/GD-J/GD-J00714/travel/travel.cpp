#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	int a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1 == c2)
	{
		a=1;
		cout<<a;
	}
	else cout<<"0";
	
	if(a==1 && s1[0] == s2[0] && s1[1] == s2[1])
	{
		b=1;
		cout<<b;
	}
	else cout<<"0";
	
	if(b==1 && a==1 )
	{
		if(s1[2] == 'F' || s1[2] == 'D')
		{
			if(s2[2] == 'D' || s2[2] == 'F') 
			{
				c=1;
				cout<<c;
			}
			else cout<<"0";
		}
		
		if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')
		{
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')
			{
				c=1;
				cout<<c;
			}
			else cout<<"0";
		}
	}
	else cout<<"0";
	
	if(a==1 && b==1 && c==1)
	{
		char n1=s1[2],n2=s2[2];
		if(int(n1)+1 == int(n2) || int(n1)-1 == int(n2))
		{
			cout<<"1";
			
		}
		else cout<<"0";
	}
	else  cout<<"0";
	
	return 0;
	
}
