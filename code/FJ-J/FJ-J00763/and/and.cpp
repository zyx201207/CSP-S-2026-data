#include<bits/stdc++.h>
using namespace std;
int maxe=0;
int a[1000005],b[1000005];
void sss(int x,int y)
{
	int d=0;
	while(x!=0)
	{
		d=d*10+x%2;
		x/=2;
	}
	while(d!=0)
	{
		b[y]=b[y]*10+d%10;
		d/=10;
	}
}
void eee(int p,int r)
{
	int ans=0;
	while(p!=0||r!=0)
	{
		if(p%10==r%10)
		{
			ans=ans*10+1;
		}
		else
		{
			ans=ans*10;
		}
		p/=10;
		r/=10;
	}
	maxe=max(maxe,ans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sss(a[i],i);
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			eee(b[j],b[i]);
		}
	}
	int q=0,u=1;
	while(maxe!=0)
	{
		q+=maxe%10*u;
		maxe/=10;
		u*=2;
	}
	cout<<q;
} 
