#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0,ans=0;
	char x;
	string s,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>x;
		for(int j=sum+1;j<=sum+a;j++)
		{
			s[j]=x;
		}
		sum+=a;
	}
	if(sum%2==0)
	{
		for(int i=sum;i>=sum/2+1;i--)
		{
			m[sum-i+1]=s[i];
		}
		for(int i=1;i<=sum/2;i++)
		{
			if(s[i]!=m[i])
			{
				ans++;
			}
		}
	}
	else
	{
		for(int i=sum;i>=sum/2+2;i--)
		{
			m[sum-i+1]=s[i];
		}
		for(int i=1;i<=sum/2;i++)
		{
			if(s[i]!=m[i])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
