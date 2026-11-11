#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a;
	string a1;
	string b;
	string b1;
	cin>>a>>a1>>b>>b1;
	if(a==b)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b1[0]&&a1[1]==b1[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
    }
    if(a1[2]<='C'&&b1[2]<='C')
    {
    	cout<<"1";
    	if(a1[2]-b1[2]==1||b1[2]-a1[2]==1)
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
	else if(a1[2]>'C'&&b1[2]>'C')
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
}
