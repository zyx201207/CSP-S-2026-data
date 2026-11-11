#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;

bool check(long long d)
{
	if(2*(4*d-2)+1<=n)
	{
		return 1;
	}
	else
	{
		if(2+(n-(2*(4*d-2)+1))/2<=k) return 1;
	}
	return 0;
}

long long er(long long l,long long r)
{
	long long ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}	
		else
		{
			l=mid+1;
		}
	}
	return ans;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k==1)
		{
			if(n==1)cout<<0<<"\n";
			else cout<<n/4+1<<"\n";
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		cout<<er(1,100000000)<<"\n";
	}
}
