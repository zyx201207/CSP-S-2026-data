#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f1,f2,f3,f4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++)
	{
		if(a[i]==c[i])
		{
			f1=1;
		}
		else
		{
			f1=0;
			break;
		}
	}
	if(f1==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	for(int i=0;i<2;i++)
	{
		if(b[i]==d[i])
		{
			f2=1;
		}
		else
		{
			f2=0;
			break;
		}
	}
	if(f2==1&&f1==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(f1==0||f2==0)
	{
		cout<<"0";
	}
	else if(f1==1&&f2==1)
	{
		if(b[2]=='A'||b[2]=='B'||b[2]=='C')
		{
			if(d[2]=='A'||d[2]=='B'||d[2]=='C')
			{
				cout<<"1";
			}
			else if(d[2]=='D'||d[2]=='F')
			{
				cout<<"0";
			}
		}
		else if(b[2]=='D'||b[2]=='F')
		{
			if(d[2]=='D'||d[2]=='F')
			{
				cout<<"1";
			}
			else if(d[2]=='A'||d[2]=='B'||d[2]=='C')
			{
				cout<<"0";
			}
		}
	}
	if(f2==1&&f1==1)
	{
		if(b[2]=='A')
		{
			if(d[2]=='B') cout<<"1";
			else cout<<"0";
	    }
	    if(b[2]=='B')
	    {
	    	if(d[2]=='A'||d[2]=='C')
	    	{
	    		cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		if(b[2]=='C')
		{
			if(d[2]=='B')
			{
				cout<<"1";
			}
			else 
			{
				cout<<"0";
			}
		}
		if(b[2]=='D')
		{
			if(d[2]=='F') cout<<"1";
			else cout<<"0";
		}
		if(b[2]=='F')
		{
			if(d[2]=='D') cout<<"1";
			else cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
