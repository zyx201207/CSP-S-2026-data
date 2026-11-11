#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],l=1,r,mid;
bool check (long long jzb)
{
	long long ans=m;
	for(int i=1;i<jzb;i++)
	{
		ans-=a[jzb]-a[i];
		if(ans<0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];//began by 1
	}
	sort(a+1,a+n+1);
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			if(!check(mid+1))
			{
				cout<<mid;
				return 0;
			}
			l=mid+1;
		}else
		{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
