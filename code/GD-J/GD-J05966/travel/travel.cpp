#include <bits/stdc++.h>
using namespace std; 

int main()
{
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	int a,b;
	char s1,s2,s3,l1,l2,l3,x;
	cin>>a>>s1>>s2>>s3;
	cin>>b>>l1>>l2>>l3;
	if(a==b)
	{
		cout<<"1";
		if(s1==l1&&s2==l2)
		{
			cout<<"1";
			if(s3==68||s3==69)
			{
				if(l3==68||l3==69)
				{
					cout<<"11";
				}
				else
				{
					cout<<"00";
				}
			}
			else
			{
				if(l3!=68&&l3!=69)
				{
					if(s3==65&&l3==67)
					{
						cout<<"10";
					}
					else if(s3==67&&l3==65)
					{
						cout<<"10";
					}
					else
					{
						cout<<"11";
					}
				}
				else
				{
					cout<<"00";
				}
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
