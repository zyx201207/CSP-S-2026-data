#include<bits/stdc++.h>
using namespace std;
char a[1000005];
char b[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	long long x,y;
	cin>>x>>y;
	string s = 0;
	string z = 0;
	int jsq = 0;
	while(x!=1)
	{
		jsq++;
		if(x%2==0)
		{
			a[jsq] = 0;
		}
		else
		{
			a[jsq] = 0;
		}
		x = x/2;
	}
	a[jsq+1] = 1;
	for(int i=jsq;i>=1;i--)
	{
		s = a[jsq];
	}
	jsq = 0;
	while(y!=1)
	{
		jsq++;
		if(y%2==0)
		{
			b[jsq] = 0;
		}
		else
		{
			b[jsq] = 0;
		}
		y = y/2;
	}
	a[jsq+1] = 1;
	for(int i=jsq;i>=1;i--)
	{
		z = b[jsq];
	}
	long long ans = s and z;
	cout<<ans;
	return 0;
}
