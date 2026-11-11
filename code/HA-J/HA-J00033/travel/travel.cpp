#include<bits/stdc++.h>
using namespace std;

string c1,c2,c3,c4;
int a,b,c,d;
string g(string a)
{
	string ans="";
	if(a.size()==3)
	{
		ans=a[0]+ans;
		ans=ans+a[1];
	}
	return ans;
}
bool ist(string a,string b)
{
	if(a[2]<='C'&&b[2]<='C')return 1;
	if(a[2]>='D'&&b[2]>='D')return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
	{
		cout<<1;
		if(g(c2)==g(c4))
		{
			cout<<1;
			if(ist(c2,c4))
			{
				cout<<1;
				if(abs(c2[2]-c4[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
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
	return 0;
}
