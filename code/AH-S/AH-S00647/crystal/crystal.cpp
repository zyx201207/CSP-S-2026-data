#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum[500010];
int n,m;
int a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int s=0;
	for(int i=n;i>=1;i--)
	{
		int l=i;
		int v=i*a[i];
		int cnt=v-sum[i];
		if(m>cnt)
		{
			s=max(s,l);
			break;
		}
	}
	cout<<s;
	return 0;
}
