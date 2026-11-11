#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool a = true,b = true,c = true,d = true;
	if(c1 != c2)
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}else
	{
		if(s1[1] != s2[1]||s1[0] != s2[0])
		{
			b = 0;
			c = 0;
			d = 0;
		}
		if(((s1[2] >= 'A'&&s1[2] <= 'C')&&(s2[2] >= 'D'&&s2[2] <= 'F'))
		||((s2[2] >= 'A'&&s2[2] <= 'C')&&(s1[2] >= 'D'&&s1[2] <= 'F')))
		{
			c = 0;
			d = 0;
		}
		else
		{
			if(s1[2]+1 != s2[2]&&s1[2]-1 != s2[2]&&s1[2]!='D'&&s1[2]!='F')
			{
				d = 0;
			}
		}
	}
	if(a)
		cout<<1;
	else
		cout<<0;
	if(b)
		cout<<1;
	else
		cout<<0;
	if(c)
		cout<<1;
	else
		cout<<0;
	if(d)
		cout<<1;
	else
		cout<<0;
	return 0;
} 
