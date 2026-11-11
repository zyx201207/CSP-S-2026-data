#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,f,f1,a[500005],b[210],s,sum=1,da;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>100)f1=1;
		if(a[i]!=i)f=1;
	}
	if(f==0)
	{
		for(int i=1;i<n;i++)
		{
			if(s+i<=m)
			{
				s+=i;
				sum++;
			}
			else
			{
				cout<<sum;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	f=0;
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[2]-a[1])
		{
			f=1;
			break;
		}
	}
	if(f==0)
	{
		int d=a[2]-a[1];
		for(int i=1;i<n;i++)
		{
			if(s+d<=m)
			{
				s+=d;
				sum++;
			}
			else
			{
				cout<<sum;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(n<=5000)
	{
		sort(a+1,a+1+n);
		for(int i=2;i<=n;i++)
		{
			s=0,sum=1;
			for(int j=i-1;j>=1;j--)
			{
				if(s+(a[i]-a[j])<=m)
				{
					s+=(a[i]-a[j]);
					sum++;
				}
				else break;
			}
			da=max(da,sum);
		}
		cout<<da;
		return 0;
	}
	if(f1==0)
	{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		a[i]+=100;
		b[a[1]]++;
		for(int i=2;i<=n;i++)
		{
			s=0,sum=0,b[a[i]]++;
			for(int j=a[i];j>=0;j--)
			{
				if(b[j]!=0)
				{
					if(s+b[j]*(a[i]-j)<=m)
					{
						s+=b[j]*(a[i]-j);
						sum+=b[j];
						continue;
					}
					sum+=((m-s)/(a[i]-j));
					s+=((m-s)/(a[i]-j))*(a[i]-j);
				}
			}
			da=max(da,sum);
		}
		cout<<da;
	}
	
	return 0;
}
