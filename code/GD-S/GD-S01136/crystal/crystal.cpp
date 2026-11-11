#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=1e12;
	}
	sort(a+1,a+n+1);
	long long ans=0,nwsum=0,nwsum1=0;
	for(int i=1;i<=n;i++)
	{
		long long k=a[i];
	    if((nwsum)*(k-a[i-1])+nwsum1<=m)
	    {
			nwsum1+=(nwsum)*(k-a[i-1]);
	    	nwsum++;
	    	//cout<<ans<<" "<<nwsum;
	    	ans=max(ans,nwsum);
	    	
		}
		else
		{
			long long sum=(nwsum)*(k-a[i-1])+nwsum1;
			while(sum>m)
			{
				sum-=(a[i]-a[i-nwsum]);
				nwsum--;
			}
			nwsum++;
			nwsum1=sum;
		}
	}
	cout<<ans;
	
	return 0;
}
