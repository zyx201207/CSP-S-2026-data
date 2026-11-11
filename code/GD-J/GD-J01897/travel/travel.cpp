#include <bits/stdc++.h>
using namespace std;
string a,d;
int main(){
	
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)

	string k,l;
	cin>>k>>a>>l>>d;
	if(k==l)
	{
		if(a[0]==d[0]&&a[1]==d[1])
		{
			if(a[2]=='A')
			{
			    if(d[2]=='B')	
			    {
			    	cout<<"1111";
				}
				else if(d[2]=='C')
				{
					cout<<"1110";
				}
				else
				{
					cout<<"1100";
				}
			}
			else if(a[2]=='B')
			{
				if(d[2]=='A'||d[2]=='C')
				{
					cout<<"1111";
			    }
			    else
			    {
			    	cout<<"1100";
				}
			}
			else if(a[2]=='C')
			{
				if(d[2]=='A')
				{
					cout<<"1110";
			    }
			    else if(d[2]=='B')
			    {
			    	cout<<"1111";
				}
			    else
			    {
			    	cout<<"1100";
				}
			}
			else if(a[2]=='D')
			{
				if(d[2]=='E') 
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1100";
				}
			}
		    else if(a[2]=='E')
			{
				if(d[2]=='D') 
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1100";
				}
			}
			
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
