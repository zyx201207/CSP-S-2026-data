#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2,n,m;
	n=0;
	string s1,s2;
	char x1,x2;
	x1=s1[2];
	x2=s2[2];
	m=x1-x2;
	
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i])
			{
				n=1;
			}
		}
		if(n==1)
		{
			cout<<"000";
			return 0;
			
		}
		else
		{
			cout<<"1";
			if(x1>='D' && x1<='F' && x2>='D' && x2<='F')
			{
				cout<<"11";
				return 0;
			}
			else if(x1>='A' && x1<='C' && x2>='A' && x2<='C')
			{
				cout<<"1";
				if(m<2 && m>-2)
				{
					cout<<"1";
					return 0;
				}
				else
				{
					cout<<"0";
				 } 
			}
			else
			{
				cout<<"00";
				return 0;
			}
		} 
	}
	return 0;
 } 
