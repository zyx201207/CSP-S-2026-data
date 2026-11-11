#include<bits/stdc++.h>
using namespace std;
long long a,b,c,f[200005],p[200005],n,r,l,ans,h;
char t[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		cin>>t[i];
	}
	
	r=n;
	l=1;
	while(l<r)
	{
		
		if(p[r]>p[l])
		{
			if(t[r]!=t[l])
			{
				ans+=p[l];
				p[r]-=p[l];
				p[l]=0;
			}
			else
			{
				p[r]-=p[l];
				p[l]=0;
			}
		}
		else
		{
			if(t[r]!=t[l])
			{
				ans+=p[r];
				p[l]-=p[r];
				p[r]=0;
			}
			else
			{
				p[l]-=p[r];
				p[r]=0;
			}
		}
		if(p[l]==0)
		l++;
		if(p[r]==0)
		r--;
	}
	cout<<ans;
	return 0;
}
