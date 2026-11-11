#include<bits/stdc++.h>
using namespace std;
long long int n,u,a[100005],a2[100005];

long long a_[100005],a2_[100005],ans;
int cnt,k,id;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char u2;
		cin>>u>>u2;
		a[i]=a[i-1]+u;
		a2[i]=u2-'a'+1;
		if(a2[i-1]==a2[i])
		{
			a[i-1]=0;
			k++;
		}
	}
	
	if(k==n-1)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			a_[++id]=a[i];
			a2_[id]=a2[i];
		}
	}
	n=id;
	for(int i=1;i<=n;i++)
	{
		a[i]=a_[i];
		a2[i]=a2_[i];
	}
	cnt=a[n]/2;
	
	if(n==2)
	{
		if(a[2]-a[1]<=a[1])cout<<a[2]-a[1];
		else cout<<a[1];
		return 0;
	}
	
	for(int i=1;i<=n/2;i++)
	{
		if(a[n-i+1]-a[n-i]<a[i]-a[i-1])
		{
			if(a2[n-i+1]==a2[i])
			{
				cnt-=a2[i];
			}
		}
	}
	cout<<cnt;
	return 0;
}
