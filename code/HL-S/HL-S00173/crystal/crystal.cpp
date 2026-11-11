#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[114514*5],sum[114514*5]; 
bool check(int x)
{
 return (a[x]*(x-1)-sum[x-1])<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	cout<<l-1<<'\n';
	return 0;
}
