#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005];
long long s[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]+s[i-1];
		int l=1,r=i;
		int an=0;
		while(l<=r)
		{
			int mid=l+r>>1;
			long long che=a[i]*(i-mid)-(s[i-1]-s[mid-1]);
			if(che<=m)
			{
				r=mid-1;
				an=i-mid+1;
			}
			else l=mid+1;
		}
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
}


