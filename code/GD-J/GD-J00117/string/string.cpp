#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll a[200005];
char c[200005];
ll na1[200005],na2[200005];
char nc1[200005],nc2[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	ll len=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
		len+=a[i];
	}
	int tn1=0,tn2=0;
	if(len%2==1)
	{
		ll mid=len/2+1;
		ll l=1;
		for(int i=1;i<=n;i++)
		{
			ll r=l+a[i]-1;
			if(l<=mid && mid<=r)
			{
				for(int j=1;j<i;j++)
				{
					na1[++tn1]=a[j];
					nc1[tn1]=c[j];
				}
				if(mid!=l)
				{
					na1[++tn1]=mid-l;
					nc1[tn1]=c[i];
				}
				if(mid!=r)
				{
					na2[++tn2]=r-mid;
					nc2[tn2]=c[i];
				}
				for(int j=i+1;j<=n;j++)
				{
					na2[++tn2]=a[j];
					nc2[tn2]=c[j];
				}
				break;
			}
			l=r+1;
		}
	}
	else
	{
		ll mid=len/2;
		ll l=1;
		for(int i=1;i<=n;i++)
		{
			ll r=l+a[i]-1;
			if(l<=mid && mid<=r)
			{
				if(mid<r)
				{
					for(int j=1;j<i;j++)
					{
						na1[++tn1]=a[j];
						nc1[tn1]=c[j];
					}
					na1[++tn1]=mid-l+1;
					nc1[tn1]=c[i];
					na2[++tn2]=r-mid;
					nc2[tn2]=c[i];
					for(int j=i+1;j<=n;j++)
					{
						na2[++tn2]=a[j];
						nc2[tn2]=c[j];
					}
				}
				else
				{
					for(int j=1;j<=i;j++)
					{
						na1[++tn1]=a[j];
						nc1[tn1]=c[j];
					}
					for(int j=i+1;j<=n;j++)
					{
						na2[++tn2]=a[j];
						nc2[tn2]=c[j];
					}
				}
				break;
			}
			l=r+1;
		}
	}
	int j=tn2;
	ll s1=0,s2=0;
	ll ans=0;
	for(int i=1;i<=tn1;i++)
	{
		s1+=na1[i];
		while(1)
		{
			if(s2+na2[j]<s1)
			{
				s2+=na2[j];	
				if(nc2[j]!=nc1[i])
				{
					ans+=na2[j];
				}
				j--;
			}
			else if(s2+na2[j]==s1)
			{
				s2+=na2[j];
				if(nc2[j]!=nc1[i])
				{
					ans+=na2[j];
				}
				j--;
				break;
			}
			else
			{	
				if(nc2[j]!=nc1[i])
				{
					ans+=s1-s2;
				}
				na2[j]-=s1-s2;
				s2=s1;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
