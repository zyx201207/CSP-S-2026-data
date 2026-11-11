#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int l=0,r=1;r<=n;r++)
	{
		for(s[r]=s[r-1]+a[r];l<r&&1ll*(r-l)*a[r]-(s[r]-s[l])>m;l++);
		ans=max(ans,r-l);
	}
	cout<<ans<<'\n';
	return 0;
}