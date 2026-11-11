#include<bits/stdc++.h>
using namespace std;

const long long MAX=500010;
long long n=0,m=0;
long long a[MAX];
long long cha[MAX]={0};
long long he[MAX]={0};
long long ans=1,li=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	
	cin>>n>>m;
	he[n-1]=0;
	cha[n-1]=0;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
    sort(a,a+n);
    for(long long i=(n-2);i>=0;i--)
    {
    	cha[i]=a[n-1]-a[i];
    	he[i]=cha[i]+he[i+1];
	}
	for(long long i =0;i<n;i++)
	{
		for(long long j=(i+1);j<n;j++)
		{
			li=he[i]-he[j]-(j-i)*cha[j];
			if(li<=m)
			{
				ans=max(ans,(j-i+1));
				
			}
			else
			{
				break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
