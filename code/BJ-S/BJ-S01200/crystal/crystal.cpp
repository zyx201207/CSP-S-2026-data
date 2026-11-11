#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010];
struct p
{
	long long s,id;
}b[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int l=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=abs(a[1]-a[2]);
	bool f=1;
	for(int i=2;i<=n;i++)
	{
		b[i].s=b[i-1].s+abs(a[i-1]-a[i])*(i-1);
		b[i].id=i;
		if(abs(a[i-1]-a[i])!=l)
		{
			f=0;
		}
	}
	long long num=1;
	if(f==1)
	{
		long long sum=0;
		int i=1;
		while(sum<=m)
		{
			sum=(l+l*i)*i/2;
			i++;
		}
		cout<<i-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i].s<=m && i>num)
		{
			num=i;
		}
		for(int j=1;j<=i;j++)
		{
			if(b[i].s-b[j].s<=m && i-j>num)
			{
				num=i-j+1;
			}
		}
	}
	cout<<num;
	return 0;
}
