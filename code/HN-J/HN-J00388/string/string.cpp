#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int cnt=0,ans=0;
	int x,j;
	string s;
	int a[200010];
	char c[200010];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	for(int i=1;i<=n;i+=x)
	{
		x=a[i],j=1;
		while(j<=x)
		{
			s[j]=c[i];
			j++;
		}
	}
	if(cnt%2==0)
	{
		for(int i=1;i<=cnt/2;i++)
		{
			if(s[i]!=s[cnt+1-i])
			{
				ans++;
			}
		}
	}
	else
	{
		for(int i=1;i<=cnt/2;i++)
		{
			if(s[i]!=s[cnt+1-i])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
