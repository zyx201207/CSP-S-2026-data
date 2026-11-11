#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
long long s[500010];
bool check(int k)
{
	for(int i=k;i<=n;i++)
	{
		int ans=a[i]*(k-1)-s[i-1]+s[i-k];
		if(ans<=m)return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	int l=1,r=n,ans,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
 	return 0;
}

