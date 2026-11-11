#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,a[5000012];
int p[5000012],q[5000012];
map<int,int>mp;
int check(int mid)
{
	for(int i=1;i<=n-mid+1;i++)
	{
	//	cout<<i<<" "<<mid<<" "<<mid*a[i+mid-1]-(q[i+mid-1]-q[i-1])<<'\n';
		if(mid*a[i+mid-1]-(q[i+mid-1]-q[i-1])<=m)
		{
			return 1;
		}
	}
	return 0;
}
int Search()
{
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)/2;
	//	cout<<l<<" "<<r<<" "<<mid<<'\n';
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}cnt++;
		if(cnt>128)break;
	}
	return mid;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]+a[i];
		p[i]=a[i]*i-q[i];
	}
	cout<<Search();
	
}
//Oct31==Dec25?
// 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
