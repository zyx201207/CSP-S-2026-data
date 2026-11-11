#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a1,a2;
string s1,s2;
int num1,num2;
char b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	
	if(a1!=a2)
	{
	  cout<<0000;
	  return 0;	
	}
	
	if(a1==a2)
	  cout<<1000;
	return 0;
}
