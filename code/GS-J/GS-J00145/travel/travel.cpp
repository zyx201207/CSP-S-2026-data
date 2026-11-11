#include<bits/stdc++.h>
using namespace std;

int main()

{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,m1,n1,c2,m2,n2;
	cin>>c1>>m1>>n1>>c2>>m2>>n2;
	
	
	if(c1 == c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		break;
		
	}
	
	if(m1 == m2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
		if(n1>='A'&&n1<='C' && n2>='A'&&n2<='C')
	{
		cout<<"1";
	}
	else if(n1>='A'&&n1<='C' && n2>='D'&&n2<=='F')
	{
		cout<<"0";
	}
	else if(n1>='D'&&n1<='F' && n2>='A'&&n2<='c')
	{
		cout<<"0";
	}
	
	if(n1 + 1 = n2 || n1 - 1 = n2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	return 0;
}
