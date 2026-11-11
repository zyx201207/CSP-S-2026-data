#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=5e5+5;

long long n,m,p,t,k,cc,ans,a[N],b[N];
bool f;

long long solve(int x)
{
	p=0;
	for(int i=x;i<=n;i++)
	{
		t=p;
		f=0;
		cc=1;
		while(t)
		{
			if(t%10==a[i])
			{
				f=1;
				k=cc;
			}
			cc++;
			t/=10;
		}
		if(f)
		{
			p/=pow(10,k-1);
		}
		else
		{
			p=p*10+a[i];
		}
	}
	return p;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans=solve(i);
		while(ans)
		{
			b[ans%10]++;
			ans/=10;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
