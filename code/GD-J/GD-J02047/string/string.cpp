#include <bits/stdc++.h>
#define ll long long
#define len first
#define ch second
using namespace std;

ll n, l, r, ans=0, lsum, rsum;
vector<pair<ll, char>> a(200005);
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	l=1, r=n;
	for(ll i=1; i<=n; i++)
	{
		ll t1; char t2; cin>>t1>>t2;
		a[i].len=t1; a[i].ch=t2;
	}
	while(l<r)
	{
		if(lsum==0)lsum=a[l].len;
		if(rsum==0)rsum=a[r].len;
		if(a[l].ch==a[r].ch)
		{
			if(lsum>rsum) lsum-=rsum, r--, rsum=0;//左边多
			else if(lsum<rsum) rsum-=lsum, l++, lsum=0;//右边多
			else r--, l++, lsum=0, rsum=0;
		}
		else
		{
			if(lsum>rsum)
			{
				lsum-=rsum, ans+=rsum, r--;//左边多
				rsum=0;
			}
			else if(lsum<rsum)
			{
				rsum-=lsum, ans+=lsum, l++;//右边多
				lsum=0;
			}
			else
			{
				ans+=lsum/*加哪个都行*/, r--, l++;
				lsum=0, rsum=0;
			}
		}
	}
	cout<<ans<<'\n'; 
	return 0;
}

