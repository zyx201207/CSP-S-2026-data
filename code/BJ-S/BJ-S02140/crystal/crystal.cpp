#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,i,ans1=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(i=1;i<=n;i++)
	{
		long long l=1,r=i,ans2;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			long long t=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(m>=t)
			{
				ans2=i-mid+1;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		ans1=max(ans1,ans2);
	}
	cout<<ans1;
	return 0;
}
