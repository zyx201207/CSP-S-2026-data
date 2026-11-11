#include"bits/stdc++.h"
using namespace std;
long long a[510000],n,m,sum,x,l,ma=0,ch=-1,tp=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(ch==-1&&i==2)
		{
			ch=a[2]-a[1];
		}
		if(ch!=-1&&a[i]-a[i-1]!=ch)
		{
			tp=1;
		}
	}
	if(tp==0)
	{
		int i=0;
		while(sum+i*ch<=m) 
		{
			sum+=i*ch;
			i++;
		}
		cout<<i;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		sum=0,l=1,x=0;
		while(sum<=m)
		{
			x++;
			if(i-l>=1)
			{
				sum+=(a[i]-a[i-l]);
				l++;
			}
			else
			{
				break;
			}
		}
		ma=max(ma,x);
	}
	cout<<ma;
	return 0;
 }
