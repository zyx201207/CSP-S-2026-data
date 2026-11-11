#include<bits/stdc++.h>
using namespace std;
long long n,m; 
long long all;
int a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>=50001)
	{
		sort(a+1,a+n+1);
		int ca=a[2]-a[1];
		ca=m/ca;
		for(int i=1;ca>0;i++)
		{
			ca=ca-i;
			all++;
		}
		cout<<min(all,n);
		return 0;
	}	
	int k[500001],mf=m;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			k[j]=a[i]-a[j];
			if(a[i]<a[j]) k[j]=INT_MIN;
		}	
		sort(k+1,k+n+1);
		sum=0;mf=m;
		for(int j=1;j<=n;j++)	
			if(k[j]<=mf)
			{
				if(k[j]>=0)
				{
					sum++;	
					mf=mf-k[j];	
				}
			}
			else break;
		all=max(all,sum);
	}
	cout<<all;
	return 0;
}
