#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,l,ll,lll,m,zuidazhi=-1000000,zhi;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					zhi=max((a[i]&a[j]),(a[j]&a[i]));
					zuidazhi=max(zhi,zuidazhi);
				}
			}
		}
		cout<<zuidazhi;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	long long x=a[1];
	for(int i=2;i<=m;i++)
	{
		x=max((x&a[i]),(a[i]&x));
	}
	cout<<x;
	return 0;
}
