#include<bits/stdc++.h>
using namespace std;

#define N 500050
int n,m,tot;
int a[N],sum[N];
bool is=false;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cha=a[n]-a[n-1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=cha)
		{
			is=true;
			break;
		}
	}
	if(!is)
	{
		int x=m;
		for(int i=n-1;i>=1;i--)
		{
			if(a[n]-a[i]<x||a[n]-a[i]==x)
			{
				tot++;
				x-=a[n]-a[i];
			}
			else break;
		}
		cout<<tot+1;
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			int x=m;
			tot=0;
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-a[j]<x||a[i]-a[j]==x)
				{
					tot++;
					x-=a[i]-a[j];
				}
				else break;
			}
			sum[i]=tot+1;
		}
		sort(sum+1,sum+n+1);
		cout<<sum[n];
	}
    return 0;
}
