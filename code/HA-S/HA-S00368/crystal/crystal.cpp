#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans=0;
int a[N],sum[N];
bool check(int l,int r)
{
	int mubiao=(r-l+1)*a[r];
	int now=sum[r]-sum[l-1];
	if(mubiao-now<=m) return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=n-i+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(check(i,i+mid-1)) l=mid;
			else r=mid;
		}
		if(check(i,i+r-1)) ans=max(ans,r);
		else if(check(i,i+l-1)) ans=max(ans,l);
	}
	cout<<ans<<endl;
	return 0;
}
