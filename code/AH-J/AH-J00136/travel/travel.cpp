#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b)
	{
		cout<<"1";
	}
	else if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	if(x[0]*10+x[1]==y[0]*10+x[1])
	{
		cout<<"1";
	}
	else if(x[0]*10+x[1]!=y[0]*10+x[1])
	{
		cout<<"000";
		return 0;
	}
	for(int i=1;i>0;i++)
	{
		if(x[2]=='A'&&(y[2]=='B'||y[2]=='C'))
		{
			cout<<"1";
			break;
		}
		else if(x[2]=='B'&&(y[2]=='A'||y[2]=='C'))
		{
			cout<<"11";
			return 0;
		}
		else if(x[2]=='C'&&(y[2]=='A'||y[2]=='B'))
		{
			cout<<"1";
			break;
		}
		else if(x[2]=='D'&&y[2]=='F')
		{
			cout<<"11";
			return 0;
		}
		else if(x[2]=='F'&&y[2]=='D')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	for(int j=1;j>0;j++)
	{
		if(x[2]=='A'&&y[2]=='B')
		{
			cout<<"1";
			return 0;
		}
		else if(x[2]=='C'&&y[2]=='B')
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	return 0;
} 
