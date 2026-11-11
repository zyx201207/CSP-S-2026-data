#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxn,k,sum=0;
int d[N],a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	for(int i=30;i>=0;i--)
	{
		int p=1<<i; sum=0;
		for(int j=1;j<=n;i++)
		{
			if((d[j]&p)!=0) sum++;
		}
		if(sum>=m)
		{
			k=i;
			break;
		}
	}
	for(int i=n;i>=0;i--)
	{
		int p=1<<i;sum=0;
	    for(int j=0;j<=n;j++)
		{
			if((d[j]&p)!=0 && a[j]==0) 
			sum++;
		}
		if(sum>=m)
		{
			maxn+=p;
			for(int j=1;j<=n;j++)
			{
				if((d[j]&p)==0)
				{
					a[j]=1;
				}
			}
		}
	}
	cout<<k<<'\n';
	return 0;
}
