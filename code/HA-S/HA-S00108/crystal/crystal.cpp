#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],l=1,r=1,ans,res;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		a[i]=a[i+1]-a[i];
		s[i]=s[i-1]+a[i];
	}
	while(r<=n)
	{
		while(res+(r-l+1)*a[r]>m)
		{
			res-=s[r-1]-s[l-1];
			l++;
			if(l>r) r++;
		}
		res+=(r-l+1)*a[r];
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans+1;
	return 0;
}
