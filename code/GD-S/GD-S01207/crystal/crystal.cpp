#include<bits/stdc++.h>
using namespace std;
long long n,m,an,a[500005],q[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1,l,r,mid;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
		l=1,r=i;
		while(l<r)
		{
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-q[i]+q[mid-1]<=m)r=mid;
			else l=mid+1;
		}
		an=max(an,i-l+1);
	}
	cout<<an;
	return 0;
}
