#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("traver.in","r",stdin);
	freopen("traver.out","w",stdout);
	string c1,c2,s1,s2;
	int a,b; 
	cin>>c1>>a>>s1>>c2>>b>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(a==b)
		{
			cout<<"1";
			if('s1==A'&&'s2==B')
			{
				cout<<"10";
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
	return 0;
 } 
