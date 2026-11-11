#include<bits/stdc++.h>
using namespace std;
long long a[10000007];
bool b[10000007];
long long c[10000007];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long p=1;p<=m;p++)
		{
			b[p]=false;
		}
		for(long long j=0+i;j<=n;j++)
		{
			if(b[a[j]]==1)
			{
				for(long long p=j-1;p>=1;p--)
				{
					if(a[p]==a[j]) break;
					b[a[p]]=false;
				}
			}
			else b[a[j]]=true; 
		}
		for(long long p=1;p<=m;p++)
		{
			if(b[p]==true)
			{
				c[p]++;
			}
		}
	}
	
	for(long long p=1;p<=m;p++)
		{
			cout<<c[p]<<" ";
		}
	
	return 0;
 } 
