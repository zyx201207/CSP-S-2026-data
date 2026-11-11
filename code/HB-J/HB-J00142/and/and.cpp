#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long yu;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=2;i<=n;i++)
	{
		for(long long j=1;j<i;j++)
		{
			for(long long k=1;k<=30;k++)
			{
				long long ans=1;
				ans*=2;
				if(a[i]+a[j]!=ans-1)
				{
					if(a[i]>=a[j])
						yu=max(yu,a[j]);
					else 
						yu=max(yu,a[i]);
				}
			}
		}
	}
	cout<<yu;
	return 0;
}
