#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],f[N],maxn;

bool check(int x,int now)	{
	if((now-x)*a[now]-f[now-1]+f[x-1]<=m)	return true;
	return false;
}
signed main()	{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	f[0]=0;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)	f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++)	{
		int l=1,r=i,ans=-1;
		while(l<=r)	{
			int mid=l+r>>1;
			if(check(mid,i))	{
				r=mid-1;
				ans=mid;
			}else l=mid+1;
		}
		if(ans==-1)	continue;
		maxn=max(maxn,i-ans+1);
	}
	cout<<maxn;
	return 0;
}
/*
Oct31==Dec25?
*/
