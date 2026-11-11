#include<bits/stdc++.h>
using namespace std;
long long int a[500005];
long long int b[500005];
int main()
{
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
	int n;
	long long int m;
	cin>>n>>m;
	if(m==0)
	{
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	long long int zd=0;
	for(int i=0;i<n;i++)
	{
		long long int ans=0;
		for(int j=0;j<n;j++)
		{
			if(a[i]>=a[j])
			{
			long long int pp=max(a[i],a[j]);
			long long int qq=min(a[i],a[j]);
			ans=ans+pp-qq;
			if(ans>m)
			{
				break;
			}else{
				b[i]++;
			}
		}else{
			continue;
		}
		}
		if(b[i]>zd)
		{
			zd=b[i];
		}
	}
	cout<<zd;
	return 0; 
} 
