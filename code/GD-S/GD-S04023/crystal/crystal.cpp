# include <bits/stdc++.h>
# define int long long 
using namespace std;
const int N=6e5+10 ;

int n , m ,  a[N] ;
int l , r , ans , num ;

bool check(int x)
{
	int d=lower_bound(a+1,a+n+1,x)-a-1 ;
	num=upper_bound(a+1,a+n+1,x)-a-1 ;
	int sum=0 ;
	for(int i=d ; i>=1 ; i--)
	{
		sum+=x-a[i] ;
	}
	
	return sum<=m ;
}
signed main()
{
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	
	cin >> n >> m ;
	for(int i=1 ; i<=n ; i++)
	{
		cin >> a[i] ;
		l=min(l,a[i]) ;
		r+=a[i] ;
	}
	sort(a+1,a+n+1) ;
	r=abs(r) ;
	while(l<=r)
	{
		int mid=(l+r)>>1 ;
		if(check(mid))
		{
			l=mid+1 ;
			ans=num ;
		}
		else
		{
			r=mid-1 ;
		}
	}
	
	cout << ans ;
	return 0;
}
