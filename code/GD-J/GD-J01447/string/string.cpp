#include <iostream>
using namespace std;
const long long N=2e5+5;
long long n;
long long a[N],st[N],ans,len,ct,cti,ced;
char c[N];

long long a2[N],st2[N];
char c2[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	st[1]=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		st[i+1]=st[i]+a[i];
	}
	len=st[n+1]-1;
	
	if(n==1)
	{
		cout<<'0';
		return 0;
	}
	
	ct=(len+1)>>1;
	
	if(len&1)
	{
		for(cti=1;cti<=n&&st[cti]<=ct;cti++);
		cti--;
		if(st[cti+1]-1>ct)
		{
			a[cti]=(ct-1)-(st[cti])+1;
			a2[n-cti+1]=(st[cti+1]-1)-ct;
			c2[n-cti+1]=c[cti];
		}
		
		for(long long i=cti+1;i<=n;i++)
		{
			a2[(n-cti)-(i-cti)+1]=a[i];
			c2[(n-cti)-(i-cti)+1]=c[i];
		}
		
		long long l1=cti;
		if((st[cti]==ct&&st[cti+1]-1==ct)||a[cti]==0)
		{
			l1--;
		}
		long long l2=(n-cti+1);
		
		st[1]=1;
		for(int i=1;i<=l1;i++)
		{
			st[i+1]=st[i]+a[i];
		}
		st2[1]=1;
		for(long long i=1;i<=l2;i++)
		{
			st2[i+1]=st2[i]+a2[i];
		}
				
		long long p2=1;
		for(long long p1=1;p1<=l1;p1++)
		{
			while(p2<=l2&&st2[p2]<=st[p1+1]-1)
			{
				if(st2[p2+1]-1>st[p1+1]-1)
				{
					if(c2[p2]!=c[p1])
					{
						ans+=st[p1+1]-st[p1];
					}
					st2[p2]=st[p1+1];
				}
				else
				{
					if(c2[p2]!=c[p1])
					{
						ans+=st2[p2+1]-st2[p2];
					}
					st[p1]=st2[p2+1]; 
					p2++;
				}
			}
		}
		cout<<ans;
	}
	else
	{
		for(cti=1;cti<=n&&st[cti]<=ct;cti++);
		cti--;
		if(st[cti+1]-1>ct)
		{
			a[cti]=ct-(st[cti])+1;
			a2[n-cti+1]=(st[cti+1]-1)-ct;
			c2[n-cti+1]=c[cti];
		}
		
		for(long long i=cti+1;i<=n;i++)
		{
			a2[(n-cti)-(i-cti)+1]=a[i];
			c2[(n-cti)-(i-cti)+1]=c[i];
		}
		
		long long l1=cti;
		long long l2=(n-cti+1);
		
		st[1]=1;
		for(int i=1;i<=l1;i++)
		{
			st[i+1]=st[i]+a[i];
		}
		st2[1]=1;
		for(long long i=1;i<=l2;i++)
		{
			st2[i+1]=st2[i]+a2[i];
		}
		
		long long p2=1;
		for(long long p1=1;p1<=l1;p1++)
		{
			while(p2<=l2&&st2[p2]<=st[p1+1]-1)
			{
				if(st2[p2+1]-1>st[p1+1]-1)
				{
					if(c2[p2]!=c[p1])
					{
						ans+=st[p1+1]-st[p1];
					}
					st2[p2]=st[p1+1];
				}
				else
				{
					if(c2[p2]!=c[p1])
					{
						ans+=st2[p2+1]-st2[p2];
					}
					st[p1]=st2[p2+1]; 
					p2++;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
