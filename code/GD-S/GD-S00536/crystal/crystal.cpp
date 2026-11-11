//code by ElderFour
//problem:crystal 
#include<bits/stdc++.h>
using namespace std;
const long long N=500010,M=1e12;
long long n,m,a[N],ans,l,r,f[N],answer;
__int128 sum,tmp;
/*
long long getmin(long long lim)//找到最小的大于等于 lim 的数
{
	long long l=0,r=n+1,mid;
	while(l+1<r)
	{
		mid=l+r>>1;
		if(a[mid]>=lim)r=mid;
		else l=mid;	
	}	
	return 
} */
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	answer=1;
	r=1;
	for(int i=2;i<=n;i++)
	{
		tmp=(i-r)*(a[i]-a[i-1]);
		sum+=tmp;
		while(sum>m&&r<i)
		{
			sum-=(a[i]-a[r]);
			r++;
		}
		answer=max(answer,i-r+1);
	}
	cout<<answer;
	return 0;
}

