#include<bits/stdc++.h>
using namespace std;
long long a[500000];
char b[500000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long sum=0;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i]>>b[i];	
	    sum+=a[i];
	    for(int j=1;j<=a[i];j++)
	    {
			s+=b[i];
		}
	}
	for(int i=1;i<n;i++)
	{
		if(b[i]!=b[i+1])
		{
			flag=0;
			break;
		}
	}
	string t;
	for(int i=n;i>=1;i--)
	{
	    for(int j=1;j<=a[i];j++)
	    {
			t+=b[i];
		}
	}
	if(flag==1)
	{
		cout<<0;
	}
	sum=(sum+1)/2;
	int ans=0;
	for(int i=1;i<=sum;i++)
	{
		if(s[i]!=t[i])
		{
			ans++;
		}
	}
	cout<<ans;
}
