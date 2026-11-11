#include<bits/stdc++.h>
using namespace std;
string s;
string c;
int n;
int a[100005],b[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>s[i];
		sum+=a[i];
		if(s[i]==s[i-1]&&i!=0)
		{
			cout<<"0";
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			c[i]=s[i];
		}
	}

	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(c[sum-i]!=c[i])
		{
			c[a[i]+a[i+1]-i]=c[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
 }
