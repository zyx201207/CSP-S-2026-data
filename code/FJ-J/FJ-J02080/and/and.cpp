#include <bits/stdc++.h>
using namespace std;
long long su=-1;
long long a[200005];
int n,m;
void fun(long long m1,long long i,long long anns)
{
	m1--;
	anns=anns&a[i];
	if(m1==0)
	{
		su=max(su,anns);
		return;
	}
	for(long long j=i+1;j<=n;j++)
		fun(m1,j,anns);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		long long maxn=-1;
		for(long long i=1;i<=n;i++)
		{
			if(maxn<=a[i])
				maxn=a[i];
		}
		cout<<maxn;
		return 0;
	} 
	if(m==n)
	{
		long long ans=a[1];
		for(long long i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}
	for(long long i=1;i<=n-m;i++)
		fun(m,i,a[i]);
	cout<<su;
	return 0;
} 
