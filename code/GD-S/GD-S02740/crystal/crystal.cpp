#include<bits/stdc++.h>
using namespace std;
const int N=1e7+3;
long long n,m;
long long a[N];
long long sum=1;
long long f=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	long long b=0;
	long long nl;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2) b=a[i]-a[i-1];
		else if(i>2)
		{
			if(a[i]-a[i-1]!=b) f=0;
		}
	} 
	sort(a+1,a+n+1);
	if(f)
	{	
		//cout<<-1;
		for(int i=n-1;i>=1;i--)
		{
			nl=m;
			long long f=a[n]-a[i];
			if(f>nl)
			{
				cout<<sum;
				return 0;
			}
			else
			{
				nl-=f;
				sum++;
				if(nl==0)
				{
					cout<<sum;
					return 0;
				}
			}
		}
	}
	nl=m;
	sum=1;
	for(int i=n;i>1;i--)
	{
		nl=m;
		long long xz;
		xz=1;
		for(int j=i-1;j>=1;j--)
		{
			long long f=a[i]-a[j];
			//cout<<a[i]<<" "<<a[j]<<" "<<f<<endl;
			if(f>nl)
			{
				sum=max(xz,sum);
				continue;
			}else{
				nl-=f;
				xz++;
				if(nl==0)
				{
					sum=max(xz,sum);
					continue;
				}
			}
		//	cout<<nl<<endl;
		}
		
		
	}
	cout<<sum;
}

