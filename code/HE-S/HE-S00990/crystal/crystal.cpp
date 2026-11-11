#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],mx=-1e9,mi=1e9,ans=0;
int s[500005];
int check(int x)
{
	int mm=m;
	int cnt=0;
	memset(s,0x7f,sizeof(s));
	for(int i=1;i<=n;i++)
	{
		s[i]=abs(x-a[i]);
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
	{
		if(s[i]<=mm)
		{
			mm-=s[i];
			cnt++;
		}
		else break;
	}
	return cnt;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(a[i],mx);
		mi=min(a[i],mi);
	}
	if(n>5000&&mx>100)
	{
		int cnt=0;
		bool niko=true;
		int mid=(a[1]+a[n])/2; 
		cout<<check(mid);
	}
	else
	{
		for(int i=mi;i<=mx;i++)
		{
			ans=max(ans,check(i));
		}
		cout<<ans;
	}
	return 0;
} 
