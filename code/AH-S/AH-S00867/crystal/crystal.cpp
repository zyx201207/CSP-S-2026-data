#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,ans;
vector<int> a;
bool check(int x)
{
	
	long long sum=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=x)
		{
			cnt++;
			sum+=x-a[i];
		}
	}
	if(sum<=m)
	{
		ans=max(ans,cnt);
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		a.push_back(x);
		r+=x;
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
