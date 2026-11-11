#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans;
bool check(int md)
{
	int mid=upper_bound(a+1,a+1+n,md)-a-1;
	int cnt=0,num=0,i=mid;
	for(;i>=1&&cnt<m;i--)
	{
		if(cnt<=m)ans=max(ans,num);
		cnt+=a[mid]-a[i];
		num++;
	}
	if(cnt<=m)
	{
		ans=max(ans,num);
		return false;
	}
	else
	{
		return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=a[1],r=a[n];
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
