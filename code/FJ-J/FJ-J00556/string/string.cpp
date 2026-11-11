#include<bits/stdc++.h>
using namespace std;
struct p
{
	char a;
	long long b;
}h[200005];
struct p1
{
	char a1;
	long long b1;
}h1[200005];
struct p2
{
	char a2;
	long long b2;
}h2[200005];
long long n,k1,k2;
long long sum,sum1,sum2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i].b>>h[i].a;
		sum+=h[i].b;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(sum1+h[i].b<=sum/2)
		{
			sum1+=h[i].b;
			h1[++k1].a1=h[i].a;
			h1[k1].b1=h[i].b;
		}
		else
		{
			
			long long p=sum/2-sum1;
			sum1+=p;
			if(p==0)
			{
				break;
			}
			h1[++k1].a1=h[i].a;
			h1[k1].b1=p;
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(sum2+h[i].b<=sum/2)
		{
			sum2+=h[i].b;
			h2[++k2].a2=h[i].a;
			h2[k2].b2=h[i].b;
		}
		else
		{
			
			long long p=sum/2-sum2;
			sum2+=p;
			if(p==0)
			{
				break;
			}
			h2[++k2].a2=h[i].a;
			h2[k2].b2=p;
			break;
		}
	}
	
	long long l1=1,l2=1;
	long long ans=0;
	while(1)
	{
		if(h1[l1].a1==h2[l2].a2)
		{
			long long o=h1[l1].b1;
			h1[l1].b1-=min(h1[l1].b1,h2[l2].b2);
			h2[l2].b2-=min(o,h2[l2].b2);
			if(h1[l1].b1==0)
			{
				l1++;
			}
			if(h2[l2].b2==0)
			{
				l2++;
			}
		}
		else
		{
			ans+=min(h1[l1].b1,h2[l2].b2);
			long long o=h1[l1].b1;
			h1[l1].b1-=min(h1[l1].b1,h2[l2].b2);
			h2[l2].b2-=min(o,h2[l2].b2);
			if(h1[l1].b1==0)
			{
				l1++;
			}
			if(h2[l2].b2==0)
			{
				l2++;
			}
		}
		if(l1>k1&&l2>k2)
		{
			
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
