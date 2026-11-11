#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long big=0;
	long long now=(1<<n)-1;
	if(n<=30)
	{
		long long mask=now;
		long long p=now;
		int cnt=0;
		while(mask>=1)
		{
			for(int i=0;i<n;i++)
			{
				if(mask&(1<<i))
				{
					p=p&a[i+1];
					cnt++;
				}
			}
			if(cnt==m)
			{
				big=max(big,p);
			}
			p=now;
			mask--;
			cnt=0;
		}
		cout<<big;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			big=max(big,a[i]);
		}
		cout<<big;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			now=now & a[i];
		}
		cout<<now;
	}
	else if(m==n-1)
	{
		long long w=now;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				w+=a[j]&w;
			}
			big=max(w,big);
			w=now;
		}
		cout<<big;
	}
	else{
		cout<<0;
	}
}