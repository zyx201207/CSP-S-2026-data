#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
bool f=1;
long long a[500005]; 
long long d[5000][5000];
long long mm;
long long cc;
long long kk;
long long ans=1,mans=-999999;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	mm=m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
		if(i>=3)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
		}
		kk+=a[i];
	}
	kk=kk-n;
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(m>=kk)
	{
		cout<<n;
		return 0;
	}
	if(f==1)
	{
		cc=abs(a[n]-a[n-1]);
		for(int i=1;i<=n;i++)
		{
			if((mm-(i*cc))>=0)
			{
				ans++;
				mm-=(i*cc);
				
			
				
			}
		}
		cout<<ans;
		return 0;
		
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			d[i][j]=a[i]-a[j];
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(d[i][j]>=0 && mm>=0 &&i!=j)
			{
				if(mm-d[i][j]>=0)
				{
					mm-=d[i][j];
					ans++;
				}
				
			}
		}
		mm=m;
		if(ans>mans)mans=ans;
		ans=1;
		
	}
	cout<<mans;
	
	
	return 0;
}