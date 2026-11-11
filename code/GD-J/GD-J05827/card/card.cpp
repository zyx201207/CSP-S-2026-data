#include<bits/stdc++.h>
using namespace std;
char a[10000005];
long long b[10000005];
string c;
long long d[10000005];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long sum=0;
		for(long long j=i;j<=n;j++)
		{
			if(b[a[j]-'0']==0)
			{
				b[a[j]-'0']=j;
				c=c+a[j];
				sum++;
			}
			else
			{
				for(long long k=b[a[j]-'0'-1];k<=sum-a[j]+'0';k++)
				{
					sum--;
					c[b[k]]='0';
					b[k]=0;
					
				}
				sum++;
				c=c+a[j];
				for(int ki=0;ki<c.size();ki++)
				{
					if(c[ki]=='0')
					{
						b[a[j]-'0']=ki+1;
					}
				 } 
			}
		}
		for(long long j=0;j<c.size();j++)
		{
			d[c[j]-'0']++;
		}
		for(long long j=i;j<=n;j++)
		{
			b[a[j]]==0;
		}
		c="";
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
 } 
