#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	int a = 0,b = 0,c = 0,d = 0;
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2)
	{
		cout<<"0000"<<endl;
		return  0;
	}
	if(c1 == c2)
	{
		a = 1;
		for(int i = 0; i < s1.size(); i++)
		{
			int m = s1[2],n = s2[2];
			int x = s1[1],y = s2[1];
			int p = s1[0],q = s2[0];

			if(x == y&&p == q)
			{
				b = 1;
				if(m <= 'C'&&n <= 'C')
				{
					c = 1;
				}
				if(m >= 'D'&&n >= 'D')
				{
					c = 1;
				}
			}
			if(m == 'A'&&n == 'B'&&x == y)
			{
				d = 1;
			}
			if(m == 'B'&&n == 'C'&&x == y)
			{
				d = 1;
			}
			if(m == 'D'&&n == 'F'&&x == y)
			{
				d = 1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return  0;
}
