#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005];
int ck(ll k,int n,ll m)
{
	for(int i=1;i<=n;i++)
		b[i]=k-a[i];
	sort(a+1,a+n+1);
	int c=0;
	for(int i=1;i<=n&&m>=b[i];i++)
		if(b[i]>=0)
			m-=b[i],c++;	
	return c;
}//O(NlogN)
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,c=0,ma=0;
	ll m,k,l=1e12,r=-1e12;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],l=min(l,a[i]),r=max(r,a[i]);
	while(l<=r)
	{
		ll mid=(l+r)/2;
		int k=ck(mid,n,m);
		if(k>=ma)
			l=mid+1,ma=k;
		else
			r=mid-1;
	}
	cout<<ma;
	return 0;
}//O(NlogNlogV)->max:T(2.5e8),WA,50pts
/*
Why WA?I`m thinking...
*/
