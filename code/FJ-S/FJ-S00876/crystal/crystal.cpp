#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool okA=1;
	bool okB=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
		if(x!=i) okA=0;
	}
	long long cha=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(cha!=a[i]-a[i-1])
		{
			okB=0;
		}
	}
	if(okA==1)
	{
		long long mA=m;
		long long cntA=1;
		for(int i=1;i<=n;i++)
		{
			if(cntA==n)
			{
				cout<<cntA;
				return 0;
			}
			if(i<=mA)
			{
				cntA++;
				mA-=i;
			}
		}
		cout<<cntA;
		return 0;
	}
	else if(okB==1)
	{
		long long mB=m;
		long long cntB=1;
		for(int i=1;i<=n;i++)
		{
			long long che=i*cha;
			if(cntB==n)
			{
				cout<<cntB;
				return 0;
			}
			if(che<=mB)
			{
				cntB++;
				mB=mB-che;
			}
		}
		cout<<cntB;
		return 0;
	} 
	else
	{
		long long mC=m;
		long long cur=-10000;
		while(true)
		{
			long long sum=0;
			for(int i=1;i<=n;i++)
			{
				if(cur>=a[i])
				{
					sum=sum+(cur-a[i]);
				}
			}
			if(sum>mC)
			{
				break;
			}
			else
			{
				cur++;
			} 
		}
		long long cntc=0;
		for(int i=1;i<=n;i++)
		{
			if(cur>=a[i])
			{
				cntc++;
			}
		}
		cout<<cntc;
		return 0;
	}
	return 0;
}
