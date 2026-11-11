#include<bits/stdc++.h>
using namespace std;
int sum=0;
char c1,s1,c2,s2;
int main()
{
	froepen("travel.in","r",stdin);
	froepen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
	if(abs(s1-s2)==1)
	{
		cout<<'1'<<'1'<<'1'; 
		return 0; 
	}
	cout<<'0'<<'0'<<'0';
	
	
	
	
	return 0;
}
