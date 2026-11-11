//GZ-J00560 陈俊达 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[110],c=0,d=0,f=0;
	string s[110],r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		c+=a[i];
	}
	if(c%2!=0)
	{
		d=c/2+1;
	}
	else
	{
		d=c/2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			r+=s[i];
		}
	}
	for(int i=0;i<d;i++)
	{
		if(r[i]!=r[c-1])
		{
			f++;
		}
		c--;
	}
	cout<<f;
	return 0;
}
