#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5000005],c[5000005],q,l,sum,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
	}
	l=1;
	for(int i=1;i<=n;i++)
	{
		while(l<i&&sum+(i-l+1)*c[i]>m)
		{
			sum-=q;
			q-=c[l];
			l++;
		}
		sum+=(i-l+1)*c[i];
		q+=c[i];
		ans=max(ans,i-l+1); 
	}
	cout <<ans+1;
	return 0;
}

