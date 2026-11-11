#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],i,j,s,s1,l,r,mid,maxn,t;
bool check(long long mid)
{
	s=0;
	s1=0;
	for(i=mid-1;i>0;i--)
	{
		
		if(s+(a[mid]-a[i])<=m) s+=(a[mid]-a[i]);
		else break;
		s1++;
	}
	return s1>maxn;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			maxn=s1;
			//cout<<mid<<' '<<maxn<<'\n';
			//t=a[mid];
		}
		else r=mid-1;
	}
	cout<<maxn+1;
	return 0;
}
