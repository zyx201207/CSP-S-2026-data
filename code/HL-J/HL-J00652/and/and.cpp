#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		int maxn=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>maxn)maxn=a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		int df11;
		for(int i=1;i<n;i++)
		{
			a[i+1]=a[i]&a[i+1];
			df11=a[i+1];
		}
		cout<<df11;
		return 0;
	}
	if(m==2)
	{
		long long maxn1=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(i&j>maxn1)
				{
					maxn1=i&j;
				}
			}
		}
		cout<<maxn1;
		return 0;
	}
	int t;
	if(m==n-1)
	{
		int maxn2=1e9;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<maxn2){
			maxn2=a[i];
			t=i;
			}
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
			if(i+1!=t){

			a[i+1]=a[i]&a[i+1];
			ans=a[i+1];
		}
		else
		{
			a[i+2]=a[i]&a[i+2];
			ans=a[i+2];
		}
		if(i==t)continue;
		}
		cout<<ans;
		return 0;
	}
	cout<<a[1]&a[2];
	return 0;
}
