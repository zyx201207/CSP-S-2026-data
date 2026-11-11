#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[100005];
long long maxn=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m=2)
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>maxn)
				{
					maxn=(a[i]&a[j]);
				}			
			}
		}
	if(m=n)
	{
		maxn=a[1]&a[2];
		for(int i=3;i<=n;i++)
		 maxn = maxn&a[i];
	}
	cout<<maxn;
	return 0;
}
