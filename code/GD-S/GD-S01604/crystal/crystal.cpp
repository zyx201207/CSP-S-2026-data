#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;ll m;
ll a[N],b[N];
ll s[N];
int c[N],d[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=1;
	b[1]=a[1];c[1]=1;d[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(a[i]!=a[i-1])b[++cnt]=a[i],c[cnt]=1,d[cnt]=i;
		else ++c[cnt];
	}
	for(int i=1;i<=n;++i)
	{
		s[i]=s[i-1]+a[i];
	}
	int j=0;int ans=0;
	for(int i=1;i<=cnt;++i)
	{
		int l=1,r=j,x=d[i]-1;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			ll t1=s[x]-s[x-mid],t2=1ll*mid*b[i];
			ll Ned=t2-t1;
			if(Ned<=m)l=mid;
			else r=mid-1;
		}
		ll t1=s[x]-s[x-r],t2=1ll*r*b[i];
		ll Ned=t2-t1;
		if(Ned<=m)ans=max(ans,c[i]+r);
		j+=c[i];
		ans=max(ans,c[i]);
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
