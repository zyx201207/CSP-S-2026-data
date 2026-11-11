#include<bits/stdc++.h> 
using namespace std;
int n,ans,al,ar,a[100000];
string s[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<a[n-i+1])
		{
			if(s[n-i+1]==s[i+1])
			{
				a[i+1]=a[i+1]-a[n-i+1]+a[i];
			}
			else
			{
				a[n-i]=a[n-i]+a[n-i+1]-a[i];
			}
		}
		else if(a[i]>a[n-i+1])
		{
			if(s[i]==s[n-i])
			{
				a[n-i]=a[n-i]-a[i]+a[n-i+1];
			}
			else
			{
				a[i+1]=a[i+1]+a[i]-a[n-i+1];
			}
		}
		if(s[i]!=s[n-i+1])
		{
			ans+=a[i];
		}
	}
	cout<<ans;
}
