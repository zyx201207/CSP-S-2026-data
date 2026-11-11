#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],n,m,minx=INT_MIN,ans,sum=INT_MIN;
bool v[N];
long long aa(long long x ,long long d,long long s)
{
	if(d>x)
	{
		sum=max(sum,s);
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			if(d==1)
			{
				s=a[i];
				aa(x,d+1,s);
			}
			else
			{
				aa(x,d+1,s&a[i]);
			}
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minx=max(minx,a[i]);
		if(i==1)
		{
			ans=a[i];
		}
		else
		{
			ans=ans&a[i];
		}
	}
	if(m==1)
	{
		cout<<minx;
		return 0;
	}
	if(m==n)
	{
		cout<<ans;
		return 0;
	}
	aa(m,1,0);
	cout<<sum;
	return 0;
}

