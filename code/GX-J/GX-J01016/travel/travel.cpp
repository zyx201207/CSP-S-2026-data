#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
string a,b,s,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>x;
	int e=0,f=0;
	e=s[2]-'0';
	f=x[2]-'0';
	if(e<f)
		swap(e,f);	
	if(a==b)
	{
		cout<<1;
		if(s[0]==x[0] && s[1]==x[1])
		{
			cout<<1;
			if(s[2]=='C' && x[2]=='D') 
			{
				cout<<"00";
				return 0;
			}	
			else	
			{
				if(e-f==1)
				{
					cout<<"11";
					return 0;
				}	
				else
				{
					cout<<"10";
					return 0;
				}	
			}	
			if(x[2]=='C' && s[2]=='D')
			{
				cout<<"00";
				return 0;
			}	
		    else	
		    {
				if(e-f==1)
					cout<<"11";
				else
					cout<<"10";
		    }	
		}
		else
			cout<<"000";
	}	
	else
		cout<<"0000";
	
	return 0;
}
