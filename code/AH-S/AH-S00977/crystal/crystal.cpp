//AH-S00977 LSJ Liu Shijie
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,a[N],m,ma=1;
bool f=1;
long long se(long long ak[])
{
	long long t=0,mx=0;
	for(int i=2;i<=n;i++)
	{
		t++;
		if(ak[i-1]!=ak[i])
		{
			mx=max(mx,t);
			t=0;
		}
	}
	return mx;
}
void dfs(long long cnt,long long x[])
{
	if(cnt>m)
	{
		return;
	}
	sort(x+1,x+n+1);
	ma=max(ma,se(x));
	if(ma==n)
	{
		cout<<n;
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		x[i]++;
		dfs(cnt+1,x);
		x[i]--;
	}
	return ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1]>>a[2];
	for(int i=3;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]-a[i-2]!=a[i]-a[i-1])
		{
			f=0;
		}
	}
	if(f)
	{
		long long da=a[2]-a[1];
		long long t;
		for(t=1;t*(t+1)*da/2<=m&&t<=n;t++){}
		t=min(t,n);
		cout<<t;
		return 0;
	}
	dfs(0,a);
	cout<<ma;
	return 0;
}
//Oct31==Dec25?
