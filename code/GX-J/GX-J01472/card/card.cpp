#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int a[1010],b[1010],c[1010],t[1010];
int n,m,ans;
int mian()
{
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ans++;
		}	
		while(ans--)
		{
			int sum=0,t1=0;
			for(int i=ans;i>=1;i--)
			{
				sum++;
				for(int k=1;k<=sum-1;k++)
					if(b[k]==a[i])
					{
						for(int j=1;j<=sum;j++)
						{
							b[i]=0;
							t1=0;
						}	
					}
				b[++t1]=a[i];	
			}	
				for(int i=1;i<=ans;i++)
						
		}	
		return 0;
}
