#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
	cout<<"0";
    }
	if(s1[1]-s2[1]==0)
	{
		cout<<"1";
	}
	else
	{
	cout<<"0";
    }
	if(s1[2]-s2[2]==1)
	{
		cout<<"1";
	}
	else if(s2[2]-s1[2]==1)
	{
		cout<<"1";
	}
	cout<<1;
	return 0;
}
