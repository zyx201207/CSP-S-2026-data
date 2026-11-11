#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i;
	ll m;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int mid = n/2;
	ll ans = -1e18;
	while(mid < n)
	{
		ll res = 1,med = a[mid],m2 = m;
		for(i=mid-1;i>=0;i--)
		{
			ll dif = med-a[i];
			if(m2 >= dif) m2 -= dif,res++;
			else break;
		}
		for(i=mid+1;i<n;i++)
		{
			if(a[i] == med) res++;
			else
			{
				mid = i-1;
				break;
			}
		}
		mid++;
		ans = max(ans,res);
	}
	cout<<ans;
	return 0;
}
