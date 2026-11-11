/*
	准考证号：GZ-J00307
	学校：华麟学校
	姓名：刘凌睿 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	int ans=a[1];
	for(int i=2;i<=n;i++)
	{
		ans=ans&a[i];
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		cout<<ans;
		return 0;
	}
	int maxx=-1;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
					maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int sum=a[1];
	for(int i=2;i<=n;i++)
	{
		if(m!=1)
		{
			sum=sum&a[i];
			m--;
		}
	}
	cout<<sum;
	return 0;
}
