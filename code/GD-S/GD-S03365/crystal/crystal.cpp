#include<bits/stdc++.h>
using namespace std;
#define int long long
int n=0,a[1145140],dp=0,p=0,cnt=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	for(;l<n||r<n;)
	{
		cnt=max(cnt,r-l+1);
		if(dp+(a[r+1]-a[r])*(r+1-l)<=p&&r<n)
		{
			r++;
			dp=dp+(a[r]-a[r-1])*(r-l);
		}
		else
		{
			l++;
			dp=dp-(a[r]-a[l-1]);
		}
	}
	cout<<cnt;
}
