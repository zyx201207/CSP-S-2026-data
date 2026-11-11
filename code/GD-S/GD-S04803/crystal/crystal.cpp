#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
long long n,m;
bool check(long long bian)
{
	long long neng=0;
	for(long long i=1;i<=bian;i++)
	{
		neng+=(a[bian]-a[i]);
	}
	return neng<=m;
}
bool cmp(long long hj,long long gh)
{
	return hj<gh;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long L=1,R=n;
	long long ans=1;
	while(L<=R)
	{
		long long mid=(L+R)/2;
		if(check(mid))
		{
			L=mid+1;
			ans=mid;
		}
		else
		{
			R=mid-1;
		}
	}
	cout<<ans;
}
