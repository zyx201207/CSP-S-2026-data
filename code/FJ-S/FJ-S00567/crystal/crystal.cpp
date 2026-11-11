#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			long long op=0,cnt=0;
			for(int j=i;j>=1;j--)
			{
				if(a[i]-a[j]<=(m-op))
				{
					cnt++;
					op+=a[i]-a[j];
				}
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn<<endl;
	}
	else
	{
		int f=(a[2]-a[1]);
		for(int i=n;i>=1;i--)
		{
			long long k=f*i*(i-1)/2;
			if(k<=m)
			{
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<1<<endl;
	}
	return 0;
}
