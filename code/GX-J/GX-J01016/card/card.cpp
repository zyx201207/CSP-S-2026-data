#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int n,m,z;
int a[500010],b[500010],c[500010],d[500010],e[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		b[i]=a[i];
		d[a[i]]++;
	}	
	for(int i=1; i<=100010; i++)
		if(d[i]>0)
			e[++z]=i;
	for(int k=1; k<=n; k++)
	{
		
		for(int i=k; i<=n; i++)	
		{
			for(int j=i-1; j>=k; j--)
			{
				if(b[i]==b[j])
				{
					for(int q=j; q<=i-1; q++)
						b[q]=-1;
				}				
			}	
				
		}
		for(int t=k; t<=n; t++)
		{
			if(b[t]!=-1)
			{
				c[b[t]]++;
			}	
			b[t]=a[t];
		}
	}	
	for(int i=1; i<=100001; i++)
		if(i==e[i])
			cout<<c[i]<<" ";
	return 0;
}


