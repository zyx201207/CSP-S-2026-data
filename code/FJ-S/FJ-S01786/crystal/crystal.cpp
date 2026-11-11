#include<bits/stdc++.h>
using namespace std;
int n,tot;
long long m,a[500005];
long long c[500005],d[500005];
bool flag=1;
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
	int ga=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=ga)
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		long long s=0;
		for(int i=1;i<=n;i++)
		{
			s+=ga*i;
			if(s>m)
			{
				tot=i;
				break;
			}
		}
		cout<<tot;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			memset(c,0,sizeof(c));
			memset(d,0,sizeof(d));
			int cnt=1;
			for(int j=1;j<i;j++)
			{
				c[j]=a[i]-a[i-j];
				d[j]=c[j]+d[j-1];
				if(d[j]<=m) cnt++;
				else break;
			}
			tot=max(tot,cnt);
		}		
	}
	cout<<tot;
	return 0;
}
