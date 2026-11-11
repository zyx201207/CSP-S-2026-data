//AH-J01662 LSJ Liu Shijie
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],l,r,mi,sp[35]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823,2147483647};
long long ma=-1,K=INT_MAX;
bool f=1;
void dfs(int stp,long long sum,int t)
{
	if(stp>m)
	{
		ma=max(ma,sum);
		return;
	}
	for(int i=t;i<=n;i++)
	{
		dfs(stp+1,sum&a[i],i+1);
	}
	return ;
}
bool sea(int k)
{
	l=1,r=33;
	while(l<=r)
	{
		mi=(l+r)/2;
		if(sp[mi]==k)
		{
			return 1;
		}
		if(sp[mi]>k)
		{
			r=mi-1;
		}
		else
		{
			l=mi+1;
		}
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!sea(a[i]))
		{
			f=0;
		}
		K=K&a[i];
	}
	if(f||m==1)
	{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	if(m==n)
	{
		cout<<K;
		return 0;
	}
	if(n<=20)
	{
		dfs(1,INT_MAX,1);
		cout<<ma;
		return 0;
	}
	return 0;
}
// Trick||Treat!
