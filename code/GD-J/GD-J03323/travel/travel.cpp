#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	bool t = false,p = false,c = false,l = false;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)
	{
		if(c1 != 1 && c1 !=16)
		{
			if(c1 != 1 && c2 != 16)
			{
				t = true;
			}
		}

	}
	if(t)
	{
		if(s1[0] == s2[0])
		{
			if(s1[1] == s2[1])
			{
				p = true;
			}
		}
	}
	if(p)
	{
		if(s1[2] >= 'D' && s1[2] <= 'F')
		{
			if(s2[2] >= 'D' && s2[2] <= 'F')
			{
				c = true;
				l = true;
			}
		}
		else
		{
			if(s1[2] >= 'A' && s1[2] <= 'C')
			{
				if(s2[2] >= 'A' && s2[2] <='C')
				{
					c = true;
				}
			}
		}
	}
	if(c&& l)
	{
		if(s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2])
		{
			l = true;
		 } 
	}
	cout<<t<<p<<c<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
