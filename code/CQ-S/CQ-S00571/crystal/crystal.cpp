#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long k;
long long a[N],h[N];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)h[i]=h[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int m=l+r>>1;
			if(a[i]*(i-m+1)-(h[i]-h[m-1])<=k)r=m-1;
			else l=m+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
