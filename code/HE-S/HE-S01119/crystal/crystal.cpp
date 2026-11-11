#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,inf=1e18;
int n,m,lst[N],ans,sum[N];

bool cmp(int a,int b)
{
	return a>b;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>lst[i];
	}
	sort(lst+1,lst+n+1,cmp);
	int l=1,r=1,s=0;
	while(l<=r&&r<=n)
	{
		while(s+lst[l]-lst[r]<=m&r<=n)
		{
			s+=lst[l]-lst[r];
			r++;
		}
		ans=max(ans,r-l);
		while(s-(lst[l]-lst[l+1])*(r-l-1)>m&&l<r)
		{
			s-=(lst[l]-lst[l+1])*(r-l-1);
			l++;
		}
		s-=(lst[l]-lst[l+1])*(r-l-1);
		l++;
		if(l>r)l==r;
		if(s<0)s=0;
	}
	cout<<ans;
	return 0;
}
