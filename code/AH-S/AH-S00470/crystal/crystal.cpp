# include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e5+10;
LL n,m,ans;
LL a[N];
bool dc=1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	LL ce;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ce=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=ce)
		{
			dc=0;
			break;
		}
	}
	if(dc)
	{
		LL k=1;
		LL cnt=0;
		while(1)
		{
			int cost=k*ce;
			if(cnt+cost<=m)
			{
				k++;
				cnt+=cost;
			}
			if(cost+cnt>m) break;
			if(k==n-1) break;
		}
		cout<<k<<"\n";
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		int pos=i-1;
		LL cnt=0,aannss=0;
		while(1)
		{
			if(pos==0) break;
			LL cost=a[i]-a[pos];
			if((cost*1LL+cnt*1LL)*1LL<=m*1LL)
			{
				cnt+=cost;
				pos--;
				aannss++;
			}
			if((cost*1LL+cnt*1LL)*1LL>m*1LL) break;
		}
		ans=max(ans,aannss+1);
		if(ans==n) break;
	}
	cout<<ans<<"\n";
	return 0;
}
