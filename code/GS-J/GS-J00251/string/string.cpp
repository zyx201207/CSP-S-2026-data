#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2,r1,r2,x1,x2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)                           
	{
		r1=0;
		r2=0;
	}
	else
	{
		r1=1;
		r2=1;
	}
	if(s1-1==s2||s2-1==s1)
	{
		x1=0;
		x2=0;
	}
	else
	{
		x1=1;
		x2=1;
	}
	cout<<r1<<r2<<x1<<x2;
	return 0;
}
