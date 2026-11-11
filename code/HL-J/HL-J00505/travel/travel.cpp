#include <iostream>
using namespace std;
int main()
{
	freopen(travel,"r","stdin")
	freopen(travel,"w","stdout")
	int c1,c2;
	cin>>c1>>c2;
	string s1,s2;
	cin>>s1>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	int t=s1[0]+s1[1];
	int q=s2[0]+s2[1];
	if(c1==c2&&t==q)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(((s1[2]=="D"&&s2[2]=="F")||(s2[2]=="D"&&s1[2]=="F")||(s1[2]=="C"&&(s2[2]=="B"||s2[2]=="A"))||(s1[2]=="B"&&(s2[2]=="C"||s2[2]=="A"))||s1[2]=="A"&&(s2[2]=="C"||s2[2]=="B"))&&c1==c2&&t==q)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(((s1[2]=="D"&&s2[2]=="F")||(s2[2]="D"&&s1[2]=="F")||(s1[2]="C"&&s2[2]=="B")||(s2[2]=="C"&&s1[2]=="B")||(s1[2]=="B"&&s2[2]=="A")||(s2[2]="A"&&s1[2]=="B"))&&c1==c2&&t==q)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
