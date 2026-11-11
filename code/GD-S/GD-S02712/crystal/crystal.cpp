#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long m,a[500005],sum[500005];
bool check(int len)
{
	for(int i=1;i+len-1<=n;i++)
	{
		if((a[i+len-1]-a[i])*(len-1)-(sum[i+len-2]-(a[i]-a[1])*(len-1))<=m)return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=(a[i]-a[1])+sum[i-1];
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+(r-l+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
		
	}
	cout<<l;
	return 0;
} 
