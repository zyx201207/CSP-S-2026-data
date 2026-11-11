#include<bits/stdc++.h>
using namespace std;
int a,b;
string ah,bh;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>ah>>b>>bh;
	if(a==b)
	{
	  cout<<"1";
	  int ap=(ah[0]-'0')*10+ah[1]-'0';
	  int bp=(bh[0]-'0')*10+bh[1]-'0';
	  if(ap==bp)
	  {
	  	cout<<"1";
	  	if(ah[2]>='A'&&ah[2]<='C'&&bh[2]>='A'&&bh[2]<='C'||ah[2]>='D'&&ah[2]<='F'&&bh[2]>='D'&&bh[2]<='F')
	  	{
	  		cout<<"1";
	  		int x=ah[2]-'0';
	  		int y=bh[2]-'0';
	  		if(max(x,y)-min(x,y)>=2)
	  		{
	  			cout<<"0";
			}
			else
			{
			cout<<"1";
		   }
		}
		else
		{
			cout<<"00";
		}
	  }	
	  else
	  {
	  	cout<<"000";
	  }
	}
	else
	{
		cout<<"0000";
	}
} 
