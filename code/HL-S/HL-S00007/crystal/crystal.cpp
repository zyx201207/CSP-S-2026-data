#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]>m)
	{
		cout<<0<<'\n';
	}
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	int l=1,r=2,d=0,s=1;
	while(r<=n)
	{
		if(d>m)
		{
			d-=b[l+1];
			s--;
			l++;
		}
		else
		{
			ans=max(s,ans);
			d+=s*b[r];
			r++;
			s++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}