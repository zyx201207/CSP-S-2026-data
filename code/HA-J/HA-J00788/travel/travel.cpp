#include<bits/stdc++.h>
using namespace std;
string a1,a,b1,b;
string a2,a3,b2,b3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a1>>a>>b1>>b;
	int a4,b4;
	int jj=0,kk=0;
	a2={a[0],a[1]};
	b2={b[0],b[1]};
	a3=a[2];
	b3=b[2];
	a4=a[2]-'A';
	b4=b[2]-'A';
	if(a3=="C"&&b3=="D")
	{
		jj=1;
	}
	if(a3=="D"&&b3=="C")
	{
		kk=1;
	}
	if(a1==b1)
	{
		cout<<"1";
		if(a2==b2)
		{
			cout<<"1";
			if(jj==0&&kk==0)
			{
				cout<<"1";
				if(a4-b4==1||b4-a4==1)
				{
					cout<<"1";
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
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
}
