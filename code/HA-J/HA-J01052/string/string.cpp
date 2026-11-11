#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],num,ans,x;
char c[200005],s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(i>1)
		{
			if(c[i]!=c[i-1])
			{
				x=1;
			}
		}
	}
	if(x==0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			num++;
			s[num]=c[i];
		}
	}
	if(num%2==0)
	{
		for(int i=1;i<=num/2;i++)
		{
			if(s[i]!=s[num-i+1])
			{
				ans++;
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=num/2+1;i++)
		{
			if(s[i]!=s[num-i+1])
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
