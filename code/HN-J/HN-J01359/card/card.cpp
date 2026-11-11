#include<bits/stdc++.h>
using namespace std;
int a[500005],p[500005],la[500005],sum[500005];
bool u[500005];
int n,m,top;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int xi=1;xi<=n;xi++)
	{
		top=0;
		memset(la,0,sizeof(la));
		memset(p,0,sizeof(p));
		for(int i=xi;i<=n;i++)
		{
			if(la[a[i]]==0)
			{
				p[++top]=a[i];
				la[a[i]]=top;
			}
			else
			{
				for(int j=la[a[i]];j<=top;j++)
					p[j]=0;
				top=la[a[i]];
				p[top]=a[i];
				la[a[i]]=top;
			}
		}
		for(int i=1;i<=top;i++)
		{
			if(p[i]!=0)
			{
				sum[p[i]]++;
			}	
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
} 
/*
 10 3
  3 1 2 1 3 2 3 1 2 1
  4 3
 1 2 1 3*/
