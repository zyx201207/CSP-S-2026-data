#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],s1[500005],s2[500005],ma;
long long l,r,mid;
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	for(long long i=2;i<=n;i++) s1[i]=b[i]*(i-1);
	for(long long i=2;i<=n;i++) b[i]+=b[i-1];
	for(long long i=2;i<=n;i++) s2[i]=s2[i-1]+s1[i];
	for(long long i=2;i<=n;i++)
	{
		l=0,r=i;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(s2[i]-s2[mid-1]-(mid-1)*(b[i]-b[mid-1])>m) l=mid;
			else r=mid;
		}
		ma=max(ma,i-r+1);
	}
	cout<<ma;
	return 0;
}
