#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long ans=0;
long long num=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long r=1,l=1;
	while(r<=n&&l<=r)
	{
		r++;
		if(num+(a[r]-a[r-1])*(r-l)<m)
		{
			num+=(a[r]-a[r-1])*(r-l);
		}
		else if(num+(a[r]-a[r-1])*(r-l)==m)
		{
			ans=max(ans,r-l+1);
			for(int i=r+1; ;i)
			{
				if(a[i]==a[r]) ans++;
				if(a[i]==a[r]&&a[i+1]!=a[r])
				{
					r=i;
					l++;
					break;
				}
				else break;
			}
		}
		else
		{
			ans=max(ans,r-l-1);
			num-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
