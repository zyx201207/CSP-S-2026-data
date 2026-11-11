#include<bits/stdc++.h>
using namespace std;
long long a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=1;
	long long cnt=0,ans=0;
	while(r<n)
	{
		while(cnt+(r-l+1)*(a[r+1]-a[r])>m&&l<=r)
		{
			cnt-=a[r]-a[l];
			l++;
		}
		cnt+=(r-l+1)*(a[r+1]-a[r]);
		ans=max(r-l+2,ans);
		r++;
	}
	cout<<ans;
	return 0;
}
