#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bool dc=1;
	int d=a[2]-a[1];
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		if(a[i]-a[i-1]!=d) dc=0;
	}
	if(m>n*a[n]-sum[n])
	{
		cout<<n;
		return 0;
	}
	if(dc)
	{
		int num=1;
		while(m-d*num>=0)
		{
			m-=d*num;
			num++; 
		}
		cout<<num;
		return 0;
	}
	int num=2;
	while(m-(num*a[num]-sum[num])>=0&&num<=n)
	{
		num++;
	}cout<<num-1;
	return 0;
} 
