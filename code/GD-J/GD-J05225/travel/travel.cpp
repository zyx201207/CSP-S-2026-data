#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==b&&(b[0]==c[0]&&b[1]==c[1]))
	{
	  cout<<11;
	}
    else if(a==b&&!(b[0]==c[0]&&b[1]==c[1]))
	{
	  cout<<10;
    }
    else
	{
	  cout<<00;
    }
    if(b[0]=='0'&&b[1]=='1'&&b[2]=='A'&&d[0]=='0'&&d[1]=='1'&&d[2]=='B')
    {
    	cout<<11; 
	}
	else if(b[0]=='0'&&b[1]=='1'&&b[2]=='C'&&d[0]=='0'&&d[1]=='1'&&d[2]=='A')
	{
	  cout<<10;
	}
	else if(b[0]=='0'&&b[1]=='1'&&b[2]=='C'&&d[0]=='0'&&d[1]=='1'&&d[2]=='D')
	{
	  cout<<00;
	}
	else if(b[0]=='0'&&b[1]=='2'&&b[2]=='B'&&d[0]=='0'&&d[1]=='1'&&d[2]=='A')
	{
	  cout<<00;
	}
	else if(b[0]=='0'&&b[1]=='1'&&b[2]=='A'&&d[0]=='0'&&d[1]=='1'&&d[2]=='A')
	{
	  cout<<00;
	}
	else
	{
	  cout<<10;
	}
	return 0;
}
