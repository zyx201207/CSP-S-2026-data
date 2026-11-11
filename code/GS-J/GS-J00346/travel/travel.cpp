#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
long long x1,x2,p1,p2;
char l1,l2;
cin>>x1>>p1>>l1>>x2>>p2>>l2;
if(x1!=x2)
{
	cout<<"0000";
	return 0;
}
else
{
	cout<<"1";
	if(p1!=p2)
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(l1=='A'||l1=='B'||l1=='C')
		{
			if(l2=='A'||l2=='B'||l2=='C')
			{
				cout<<"1";
				if(max(l1,l2)-min(l1,l2)==1)
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
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			if(l2=='D'||l2=='F')
			{
				cout<<"11";
				return 0;
			}
			else
			{
				cout<<"00";
			}
		}
	}
}
}
