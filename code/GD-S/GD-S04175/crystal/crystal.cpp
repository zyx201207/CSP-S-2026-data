#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=5e5+10;
ll n,m,a[N],ans;
bool chk1(ll t)
{
	ll s,cnt;
	for(int i=t;i<=n;i++)
	{
		s=0,cnt=1;
		for(int j=1;j<=i;j++)
		{
			s+=a[i]-a[j];
			if(s>m) break;
			cnt++;
			if(cnt>=t) return true;
		}
	}
	return s<=m;
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	bool v=1;
	ll s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2) s=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=s) v=0;
	}
	if(v)
	{
		for(int i=n;i>=1;i--)
		{
			ll t=s*i*(i-1)/2;
			if(t<=m) 
			{
				cout<<i;
				break;
			}
		}
		return 0;
	}
	sort(a+1,a+1+n);
//	cout<<lower_bound(a+1,a+1+n,4)-a;
	ll l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
//		ll q=chk(mid);
		if(chk1(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l;
}
