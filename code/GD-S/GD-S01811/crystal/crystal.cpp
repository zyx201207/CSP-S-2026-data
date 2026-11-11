#include<bits/stdc++.h>
using namespace std;
int n,cnt,zd;
long long a[500003],r=-1e18,l=1e18,mid;
long long m;
bool check(int g,int k)
{
	int sum=0;
	cnt=0;
	for(int i=k;i<=n;i++)
	{
		if(g>=a[i]){sum+=g-a[i];cnt++;}
		if(sum>m)
		{
			cnt=0;
			return false;
		}
	}
	return true;;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
			for(int i=1;i<=n;i++)
		{
				l=a[i],r=a[n];
			while(l<=r)
			{
				mid=l+(r-l)/2;
				if(check(mid,i))l=mid+1;
				else r=mid-1;
				zd=max(zd,cnt);
			}
		}	
	}
	else
	{
			l=a[1],r=a[n];
			while(l<=r)
			{
				mid=l+(r-l)/2;
				if(check(mid,1))l=mid+1;
				else r=mid-1;
				zd=max(zd,cnt);
			}
	}
	cout<<zd;
	return 0;
}
