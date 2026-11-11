#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1;//che
	int c2;//che1
	int s1;//zuo
	int s2;//zuo1
	int ans;
	string c3;
	string c4;
	cin>>c1>>s1>>c3>>c2>>s2>>c4;
    if(c1==c2)
    {
    	cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2&&s1==s2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2&&s1==s2)
	{
		if(c3=="F"&&c4=="A")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="F"&&c4=="B")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="F"&&c4=="C")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="D"&&c4=="A")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="D"&&c4=="B")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="D"&&c4=="C")
		{
			ans=0;
			cout<<"0";
	    }
		else if(c3=="A"&&c4=="F")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="B"&&c4=="F")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="C"&&c4=="F")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="A"&&c4=="D")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="B"&&c4=="D")
		{
			ans=0;
			cout<<"0";
		}
		else if(c3=="C"&&c4=="D")
		{
			ans=0;
			cout<<"0";
	    }
	    else
	    {
	    	ans=1;
	    	cout<<"1";
		}
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2&&s1==s2&&ans==1)
	{
		if(c3=="A"&&c4=="B")
		{
			cout<<"1";
		}
		else if(c3=="A"&&c4=="B")
		{
			cout<<"1";
		}
		else if(c3=="B"&&c4=="C")
		{
			cout<<"1";
		}
		else if(c3=="C"&&c4=="B")
		{
			cout<<"1";
		}
		else if(c3=="D"&&c4=="F")
		{
			cout<<"1";
		}
		else if(c3=="F"&&c4=="D")
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
