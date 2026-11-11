#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],ans;
long long dg(long long x,long long t,long long sum,long long ss)
{
	if(sum<ss) return 0;
	if(x==t) return 1; 
	long long as=0;
	long long k=x+1;
	long long b[20005];
	b[0]=0;
	while(a[k]-a[x]<=d&&k<=t)
	{
	    b[0]++;
	    b[b[0]]=k;
	   	k++;
	}
	for(int i=b[0];i>=1;i--)
	{
		as+=dg(b[i],t,sum,ss+1);
	    if(as>2) break;
	}
	return as; 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0)
	{
		t--;
		ans=0ll;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>a[i];
		for(long long i=1;i<=n-3;i++)
		{
			for(long long ij=i+3;ij<=n;ij++)
			{
				long long sum=0;
				long long j=i;
				while(j<ij)
				{
					sum++;
					int k=j+1;
					while(a[k]-a[j]<=d&&k<=ij) k++;
					if(j==k-1)
					{ 
						sum=-1;
					    break;
					}
					j=k-1;
				}
				if(sum!=-1) 
				{
					if(dg(i,ij,sum,0)==2)
					{
				   		ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
