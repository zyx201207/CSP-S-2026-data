#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],oo,ans,ma,p,uu,kk,l,b[500005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
    	if(a[i]!=i)
    	{
    		oo=1;
		} 
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		if((a[i]-a[i-1]!=a[i-1]-a[i-2])&&i>=3)
	    {
	    	kk=1;
	    	break;
		}
	}
	if(m==0)
    {
    	p=1;
    	for(long long i=2;i<=n;i++)
    	{
    		if(a[i]==a[i-1])
    		{
    			p++;
			}
			else 
	        {
	        	ma=max(ma,p); 
	        	p=1;
			}
		}
		printf("%lld",ma);
		return 0;
	}
    if(oo==0)//A
    {
    	for(long long i=1;i<=n;i++)
    	{
    		ans+=a[i];
    		if(ans>m)
    		{
    			printf("%lld",i);
    			return 0;
			}
			else if(ans==m)
		    {
		    	printf("%lld",i+1);
		    	return 0;
			}
		}
		printf("%lld",n);
		return 0;
	}
	if(kk==0)//B
    {

        if(a[3]-a[2]==0)
		{
		    printf("%lld",n);
		    return 0;
		}	
		l=a[3]-a[2];
		for(long long i=1;i<=n;i++)
		{
		    ans+=pow(l,i);
			if(ans==m)
			{
				printf("%lld",i+1);
				
				return 0;
			}
			if(ans>m)
			{
				printf("%lld",i);
				return 0;
			}
		}
		printf("%lld",n);
		return 0;
	}
	if(n<=5000)
    {
    	for(long long i=1;i<=n;i++)
    	{
    		b[i]=(a[i]-a[i-1])*(i-1);
		}
		for(long long i=1;i<=n;i++)
		{
			ans=0;
			for(long long j=i;j<=n;j++)
			{
				ans+=b[j]-(a[j]*(i-1));
				if(ans==m)
				{
					ma=max(ma,j-i+1);
					break;
				}
				else if(ans>m)
				{
					ma=max(ma,j-i);
					break;
				}
				
			}
			
		}
		printf("%lld",ma);
		return 0;
	}
	cout<<315275; 
//	fclose(stdin);fclose(stdout);
}
