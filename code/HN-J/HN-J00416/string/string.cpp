#include<bits/stdc++.h>
using namespace std;
long long gs[200005],n;
char a[200005];
char qzm(long long c)
{
	for(long long i=1;i<=n;i++)
	{
		c-=gs[i];
		if(c<=0)
		{
			return a[i];
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long len=0,js=0,hz=0,zt=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		int cd;
		cin>>cd;
		len+=cd;
		if(cd%1000000000==0)
		{
			hz++;
		}
		gs[i]=cd;
		cin>>a[i];
	}
	if(hz==n)
	{
		for(long long i=1;i<=n;i++)
		{
			len=len-gs[i];
			gs[i]=gs[i]/1000000000;
			len=len+gs[i];
			zt=1;
		}
	}
	if(len%2==0)
	{
		long long len_b=len/2,nn=len;
		for(long long i=1;i<=len_b;i++)
		{
			if(qzm(i)!=qzm(nn))
			{
				js++;
			}
			nn--;
		}
	}
	else
	{
		long long len_b=(len-1)/2,nn=len;
		for(long long i=1;i<=len_b;i++)
		{
			if(qzm(i)!=qzm(nn))
			{
				js++;
			}
			nn--;
		}
	}
	if(zt==1)
	{
		cout<<js*1000000000;
		return 0;
	}
	cout<<js;
	return 0;
}
