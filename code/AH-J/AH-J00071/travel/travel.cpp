#include<bits/stdc++.h>
using namespace std;
int a[28][28];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	int a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=17;i++)
	{
		if(c1==c2)
		{
			cout<<"1";
		}
		else if(c1!=c2)
		{
			cout<<"0";
		}
	}
	a==lenth.s1(2,2);
	b==lenth.s2(2,2);
	if(a==b)
			{
				cout<<"1";
				
			}
			else if(a!=b)
			{
				cout<<"0";
			}
	if(a==C&&b==D||a==D&&b==C)
				{
					cout<<"1";
				}
				else{
					cout<<"0";
				}
	c==lenth.s1(0,1);
	d==lenth.s2(0,1);
	if(c==d)
	{
		cout<<"1";
	}
	else if(c!=d)
	{
		cout<<"0";
	}
	
	return 0;
}
