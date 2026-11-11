#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int l=1,r=1;
	int sum=0;
	while(l!=n||r!=n)
	{
		if(r==n&&r-l+1<=ans)break;
		if(sum>m)
		{
			sum-=(r-l)*(a[l]-a[l+1]);
			l++;
			continue;
		}
		ans=max(ans,r-l+1);
		if(r<n)
		{
			r++;
			sum+=(a[l]-a[r]);
		}
		else
		l++;
	}
	cout<<ans;
	return 0;
}

