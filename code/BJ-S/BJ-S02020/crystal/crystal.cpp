#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
const ll INF=1000000000000000000;
int n,mx=0;
ll a[N],m,s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	s[0]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if (n<=5000)
	{
		int tot=0;
		ll tmp=m;
		for (int i=1;i<=n;i++)
		{
			tot=0;
			tmp=m;
			for (int j=i-1;j>=1;j--)
			{
				if (a[i]-a[j]>tmp) break;
				tot++;
				tmp-=(a[i]-a[j]);
			}
			mx=max(mx,tot+1);
		}
		cout<<mx;
	}
	else
	{
		int l,r,best,mid;
		for (int i=1;i<=n;i++)
		{
			l=1,r=i-1,best=-1;
			while (l<=r)
			{
				mid=(l+r)/2;
				if ((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
				{
					best=mid;
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			if (best!=-1) mx=max(mx,i-best+1);
		}
		cout<<mx;
	}
	return 0;
}
