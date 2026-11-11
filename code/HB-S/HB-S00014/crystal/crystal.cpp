#include <bits/stdc++.h>
using namespace std;
int n,ans=-1;
long long m,maxn=-1000000000005,minn=1000000000005;
long long a[500005];
long long m1=m;int cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(m>100000000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			m1=m;
			cnt=0;
			for(int j=i;j>=1;j--)
			{
				if(m1-a[i]+a[j]>=0)
				{
					m1-=a[i]-a[j];
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		m1=m;
		cnt=0;
		for(int j=i;j>=1;j--)
		{
			if(a[j]>a[i]) continue;
			if(m1-a[i]+a[j]>=0)
			{
				m1-=a[i]-a[j];
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
