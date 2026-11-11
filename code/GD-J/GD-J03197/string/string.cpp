#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l=1,r,ans=0;
ll x[200005],y[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		char ch;
		scanf("%lld %c",&x[i],&ch);
		y[i]=ch-'a'+1;
	}
	r=n;
	while(l<=r)
	{
		if(y[l]!=y[r])
		{
			if(x[l]>x[r])
			{
				ans=ans+x[r];
				x[l]-=x[r];
				r--;
			}
			else
			{
				if(x[l]<x[r])
				{
					ans=ans+x[l];
					x[r]-=x[l];
					l++;
				}
				else
				{
					ans=ans+x[r];
					l++;
					r--;
				}
			}
		}
		else
		{
			if(x[l]>x[r])
			{
				x[l]-=x[r];
				r--;
			}
			else
			{
				if(x[l]<x[r])
				{
					x[r]-=x[l];
					l++;
				}
				else
				{
					l++;
					r--;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
