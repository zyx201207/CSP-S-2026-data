#include<bits/stdc++.h>
using namespace std;
long long m,maxn,maxx,minn=LLONG_MAX;
long long a[500005],f[500005];
int n,mm;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]),minn=min(minn,a[i]);
	sort(a+1,a+n+1);
	if(a[2]-a[1]==a[3]-a[2]&&a[4]-a[3]==a[2]-a[1]&&a[5]-a[4]==a[6]-a[5]&&a[6]-a[5]==a[2]-a[1])
	{
		long long tc=a[2]-a[1],ts=0,fs=0;
		while(mm<n-1)
		{
			ts+=tc;
			if(fs+ts<=m) mm++,fs+=ts;
			else break;
		}	
		cout<<mm+1;
	}
	else
	{
		for(int i=minn;i<=maxx;i++)
		{
			long long ts=0;
			int p=upper_bound(a+1,a+n+1,i)-a-1;
			for(int j=1;j<=p;j++)
			{
				ts+=(a[p]-a[j]);
			}
			if(ts<=m) maxn=max(maxn,(long long)(p));
		}
		cout<<maxn;
	}
	return 0;
}
