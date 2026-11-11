#include <bits/stdc++.h>
using namespace std;
int c1[20],s1[20],c2[20],s2[20],n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travsl.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>c1[i]>>s1[i]>>c2[i]>>s2[i];
	}
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1==s2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}