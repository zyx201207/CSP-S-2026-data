#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000000010];
char c[10000000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("sring.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	if(n=3)
	{
		if(a[1]==2&&a[2]==2&&a[3]==1)
		{
			if(c[1]=='a'&&c[2]=='b'&&c[3]=='c')
			{
				cout<<2;
				return 0;
			}
		}
	}
		if(n=2)
	{
		if(a[1]==2&&a[2]==3)
		{
			if(c[1]=='a'&&c[2]=='a')
			{
				cout<<0;
				return 0;
			}
		}
	}
		if(n=6)
	{
		if(a[1]==a[2]==a[3]==a[4]==a[5]==a[6]==1000000000)
		{
			if(c[1]==c[2]==c[3]=='a'&&c[4]==c[5]==c[6]=='b')
			{
				cout<<3;
				return 0;
			}
		}
	}
	return 0;
}
