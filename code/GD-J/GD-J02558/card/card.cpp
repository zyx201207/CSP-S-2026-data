#include<iostream> 
using namespace std;
long long n,m;
long long a[500010],b[500010];
long long t[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			b[j] = 0;
		}
		for(long long j = 0;j<n;j++)
		{
			bool vis = 0;
			long long cnt = 0,c = 0;
			for(long long k = 0;k<cnt;k++)
			{
				if(a[k]==a[j]) 
				{
					vis ==1;
					c = k;
					break;
				}
			}
			if(vis==0)
			{
				b[cnt] = a[j];
				cnt++;
			}
			else
			{
				for(int k = c+1;k<cnt;k++)
				{
					b[k]=0;
				}		
			}
			
		}
		for(int j = 1;j<=m;j++)
		{
			for(int k = 0;k<n;k++)
			{
				if(b[k]==j) t[j]++;break;
			}
		}
	}
	for(int i = 1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
 } 
