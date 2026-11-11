#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,n,d;
int ans,l,r;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	//for (int i=1;i<=n;i++)
	//cout<<a[i]<<" ";
	l=1;
	r=1;
	while (l<n)
	{
		//cout<<d<<" ";
		if (r==n)
		l++;
		else if (d>m)
		l++;
		else r++;
		d=(r-l)*(a[r]-a[r-1])-(a[r-1]-a[l-1]);
		if (d<=m)
		ans=max(ans,r-l+1);
		//cout<<l<<" "<<r<<"\n";
	}
	cout<<ans;
	return 0;
}
