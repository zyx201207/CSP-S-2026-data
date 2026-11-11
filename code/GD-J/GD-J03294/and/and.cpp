#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	} 
	if(m==1)
	{
		cout<<maxn;
	}
	else if(m==2)
	{
		maxn=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
				{
					continue;
				}
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	return 0;
}
