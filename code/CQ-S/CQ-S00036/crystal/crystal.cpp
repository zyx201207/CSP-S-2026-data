#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+8;
int n,m,ans,a[N],s[N];
int w(int l,int r)	{return a[r]*(r-l+1)-s[r]+s[l-1];}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	s[i]=s[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++)
	{
		while(w(l,r)>m)	l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
