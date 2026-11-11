#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long l,sum=0,ans=0,sss=1,sum1=0;
	scanf("%lld",&l);
	vector<long long> a(l+10);
	vector<char> s(l+10);
	for(long long i=1;i<=l;i++)
	{
		scanf("%lld %c",&a[i],&s[i]);
		sum+=a[i];
	}
	vector<long long> s1(sum+10);
	for(long long i=1;i<=l;i++)
	{
		int y=s[i]-'a'+1;
		for(long long j=1;j<=a[i];j++)
		{
			s1[j+sum1]=y;
		}
		sum1+=a[i];
	}
	if(sum%2==0)
	{
		for(long long i=1;i<=sum/2;i++)
	    {
		    if(s1[i]!=s1[sum-i+1])
		    {
		    	ans++;
		    }
		    else
		    {
		    	continue;
		    }
	    }
	}
	else
	{
		for(long long i=1;i<=(sum+1)/2;i++)
	    {
	    	if(s1[i]!=s1[sum-i+1])
	    	{
	    		ans++;
	    	}
	     	else
	    	{
	    		continue;
	    	}
	    }
	}
	printf("%lld",ans);
	return 0;
 } 
