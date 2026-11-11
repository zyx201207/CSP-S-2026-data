#include<bits/stdc++.h>
using namespace std;

const int N=1e6;

long long n,m,a[N],ans=-1;
long long vx[N];

int main()
{
	cin.tie(0); 
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
//	
//		for(long long i=1;i<=n;i++)
//	{
//
//		cout<<a[i]<<" ";
//	}
//
//	cout<<"\n";
	
	
	
	
	
	
	
		for(long long i=1;i<=n+1;i++)
	{		
		
//		cout<<a[i]<<" - "<<a[i-1]<<" = "<<a[i]-a[i-1]<<"\n";
		vx[i]=a[i]-a[i-1];
//		cout<<vx[i]<<" ";
	}
	long long tmx=0,thf=0;
	if(n<=5000)
	{
		for(long long i=1;i<n;i++)
	{
		if(tmx>(n-i))
		{
			break;
		}
		thf=0;
		long long j=i+1;
		while(j<=n)
		{
//			cout<<"V"<<vx[j];
			thf+=(j-i)*vx[j];
			j++;
			if(thf>m)
			{
				j--;
						if((j-i)>tmx)
						{
						tmx=j-i;
						}
			break;
			}
		}
		if((j-i)>tmx)
		{
			tmx=j-i;
		}
		if(j>=n)
		{
			break;
		}
//		i=j;
//		cout<<thf<<"\n";

	}
	}
	else
	{
		long long ex=vx[3];
		long long ppk=12345;
		while((((1+ppk)*ppk*ex)/2)>m)
		{
			ppk--;
		}
		tmx=ppk+1;
	}
	cout<<tmx;
	
	
	
	return 0;
}
