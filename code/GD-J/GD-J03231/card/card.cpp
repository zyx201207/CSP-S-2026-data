#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[50000];
int k[50000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long e=0;
		int x[50000]={0};
		int c[50000]={0};
		for(int j=i;j<=n;j++)
		{
			if(!c[a[j]])
			{
				e++;
				x[e]=a[j];
				c[a[j]]++;
			}
			else
			{
				while(x[e]!=a[j])
				{
					c[x[e]]--;
					x[e]=0;
					e--;
				}
			}
		}
		for(int i=1;i<=e;i++)
		{
			k[x[i]]++;	
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<k[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
