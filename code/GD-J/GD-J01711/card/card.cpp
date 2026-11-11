#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N],b[N],c[N],i;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(int s=i;s<=n;s++)
		{
			b[s]=a[s];
		}
		for(int j=i;j<=n;j++)
		{
			for(int p=i;p<=j;p++)
			{
				if(a[p]==a[j])
				{
					for(int k=1;k<=j-1;k++)
					{
						b[k]=0;
					}
				}
			}
		}
		for(int d=1;d<=m;d++)
		{
			int p=d;
			for(int j=i;j<=n;j++)
			{
				if(p==b[j])
				{
					c[p]++;
					cout<<c[p]<<" "; 
				}
			}
		}
		for(int s2=i;s2<=n;s2++)
		{
			b[s2]=0;
		} 
	}
	for(int s3=1;s3<=m;s3++)
	{
		cout<<c[s3]<<" ";
	}
	
	
	
	
return 0;	
}
