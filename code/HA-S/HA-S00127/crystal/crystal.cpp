#include<bits/stdc++.h>
using namespace std;
const int N=500010;
#define int long long
int a[N],S[N],n,m;
inline int s(int l,int r)
{
	return S[r]-S[l-1];
}
inline bool check(int l,int r)
{
	return a[r]*(r-l+1)-s(l,r)<=m;
}
inline int rf(int i)
{
	int l=1,r=i,m;
	while(l<=r)
	{
		m=l+r>>1;
		if(check(m,i))
		{
			r=m-1;
		}
		else
		{
			l=m+1;
		}
	}
	return l;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		S[i]=S[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,i-rf(i)+1);
	}
	cout<<ans;
	return 0;
}
