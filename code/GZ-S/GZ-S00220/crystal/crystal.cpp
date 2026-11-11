/*
	准考证号：GZ-S00220
	学校：华麟学校
	姓名：刘凌睿 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],n,m,num[500005];
int check(int x)
{
	int cnt=0,m1=m;
	for(int i=1;i<=n;i++)
	{
		num[i]=a[x]-a[i];
	}
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)
	{
		if(num[i]>=0)
		{
			if(m1-num[i]>=0)
			{
				cnt++;
				m1-=num[i];
			}
		}
	}
	return cnt;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(check(mid)>ans)
		{
			ans=check(mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
