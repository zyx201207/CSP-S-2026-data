#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5000005];
int n,m;
int s[5000005];
bool check(int mid,int l)
{
	int sum=(mid-l)*a[mid]-s[mid-1]+s[l-1];
	return sum<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid,i)) l=mid+1;
			else r=mid-1;
		}
		mx=max(mx,r-i+1);
	}
	cout<<mx;
	return 0;
} 
