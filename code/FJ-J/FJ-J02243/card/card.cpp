#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
long long a[N],b=0,c=1,d,n,m,max1,l[N];
long long x[N],y[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n; 
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		y[a[i]]=0;
		x[a[i]]=0;
	}
	for(int i=1;i<=n;i++)
	{
		c=i;
		for(int j=1;j<=m;j++)
		{
			x[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			x[a[j]]++;
			if(x[a[j]]!=1)
			{	
				while(a[c]!=a[j])
				c++;
				for(int k=c;k<j;k++)
				{
					x[a[k]]--;	
				}
				c=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(x[j]>0)
			{
				y[j]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<y[i]<<' ';
	}
//10 3 3 1 2 1 3 2 3 1 2 1 g4 3 1 2 1 3
	return 0;
 } 
