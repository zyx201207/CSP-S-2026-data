#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,ans=1;
int l,r,sum;
int a[N];
bool jc(int k)
{
	sum=0;
	for(int i=1;i<k;i++)
		sum+=a[k]-a[i];
	return sum<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(jc(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
