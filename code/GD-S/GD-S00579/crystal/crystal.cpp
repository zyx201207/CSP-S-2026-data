#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	vector<long long>a(n+1),sum(n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end(),cmp);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(1+n-i-ans<=0)break;
		if(ans*a[i]-sum[i+ans-1]+sum[i-1]<m)
		{
			long long mm=m-(ans*a[i]-sum[i+ans-1]+sum[i-1]);
			int ii=i+ans-1;
			while(mm>=0&&ii<n)
			{
				ii++;
				if(a[i]-a[ii]<=mm)
				{
					mm=mm-a[i]+a[ii];
					ans=ii-i+1;
					// if(ans==315276)
					// cout<<mm<<' '<<ii<<' '<<i<<' '<<ans<<' '<<a[ii]<<'\n';
						// cout<<mm<<' '<<ii<<' '<<i,exit(0);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}