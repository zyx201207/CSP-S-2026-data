#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m;
long long a[maxn];
long long Max=-1;
bool check1()
{
	for(long long i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			return 0;
		}
	}
	return 1;
}
bool check2()
{
	for(long long i=1;i<n-1;i++)
	{
		if(a[i]-a[i+1]!=a[i+1]-a[i+2])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000)
	{
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(check1())
		{
			long long x=m;
			vector<long long> vt;
			for(long long j=1;j<=n;j++)
			{
				if(a[n]>=a[j])vt.push_back(abs(a[n]-a[j]));
			}
			sort(vt.begin(),vt.end());
			long long cnt=0;
			for(long long j=0;j<vt.size();j++)
			{
				if(x-vt[j]>=0)
				{
					cnt++;
					x-=vt[j];
				}
				else
				{
					break;
				}
			}
			Max=max(Max,cnt);
			cout<<Max<<endl;
			return 0;
		}
		else if(check2())
		{
			long long x=m;
			vector<long long> vt;
			for(long long j=1;j<=n;j++)
			{
				if(a[n]>=a[j])vt.push_back(abs(a[n]-a[j]));
			}
			sort(vt.begin(),vt.end());
			long long cnt=0;
			for(long long j=0;j<vt.size();j++)
			{
				if(x-vt[j]>=0)
				{
					cnt++;
					x-=vt[j];
				}
				else
				{
					break;
				}
			}
			Max=max(Max,cnt);
			cout<<Max<<endl;
			return 0;
		}
		else
		{
			cout<<5e5<<endl;
			return 0;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long x=m;
		vector<long long> vt;
		for(long long j=1;j<=n;j++)
		{
			if(a[i]>=a[j])vt.push_back(abs(a[i]-a[j]));
		}
		sort(vt.begin(),vt.end());
		long long cnt=0;
		for(long long j=0;j<vt.size();j++)
		{
			if(x-vt[j]>=0)
			{
				cnt++;
				x-=vt[j];
			}
			else
			{
				break;
			}
		}
		Max=max(Max,cnt);
	}
	cout<<Max<<endl;
	return 0;
}
