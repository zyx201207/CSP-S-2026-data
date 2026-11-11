#include <bits/stdc++.h>

using namespace std;

#define int long long
#define f first
#define s second
#define SIZE 500005
int n,m;
int a[SIZE],c[SIZE],rel[SIZE],sum[SIZE],cnt[SIZE];
int check(int l,int r)
{
	return sum[r]-sum[l-1]-(l-1)*(rel[a[r]]-rel[a[l-1]]);
}
signed main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m ;
	
	for (int i=1;i<=n;++i)
	{
		cin >> a[i] ;
		c[i]=a[i];
	}
	
	sort (c+1,c+n+1);
	
	for (int i=1;i<=n;++i)
	{
		int pos=lower_bound(c+1,c+n,a[i])-c;
		rel[pos]=a[i];
		a[i]=pos;
		cnt[a[i]]++;
	}
	
	sort (a+1,a+n+1) ;
	
	for (int i=2;i<=n;++i)
	{
		sum[i]=(i-1)*(rel[a[i]]-rel[a[i-1]])+sum[i-1];
	}
	
	int ans=1;
	for (int i=2;i<=n;++i)
	{
		int l=0,r=i;
		while (l<r-1)
		{
			int mid=(l+r)>>1;
			if (check(mid,i)>m)
				l=mid;
			else
				r=mid;
		}
		
		ans=max(ans,i-r+1) ;
	}
	
	cout << ans ;
	
	return 0;
}
