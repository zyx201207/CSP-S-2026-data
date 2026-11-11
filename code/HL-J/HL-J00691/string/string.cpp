#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,flag=0;
	cin>>n;
	ll a[n+5]={};
	char b[n+5]={}; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<n;i++)
	{
		if(b[i]!=b[i+1])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<0;
		return 0;
	}
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		
		int j=n+1-i;
		if(i>=j)
		{
			break;
		}
		if(a[i]==a[j]&&b[i]==b[j])
		{
			continue;
		}
		else if(a[i]==a[j]&&b[i]!=b[j])
		{
			cnt+=a[i];
			continue;
		}
		else if(a[i]!=a[j]&&b[i]==b[j])
		{
			cnt+=max(a[i]-a[j],a[j]-a[i]);
			continue;
		}
		else
		{
			cnt+=max(a[i],a[j]);
			a[i+1]-=max(a[i]-a[j],a[j]-a[i]);
			continue;
		}
	}
	cout<<cnt;
	return 0;
}
