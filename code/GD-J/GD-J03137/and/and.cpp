#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b[1000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++)
	{
		long long ans=0;
		for(long long j=1;j<=n;j++)
		{
			if(a[j]>=a[j-1])
			{
				long long panduan=0;
				for(int q=0;q<m;q++)
				{
					if(ans==a[j])
					{
						panduan++;
					}
				}
				if(panduan==0)
				{
					ans=a[j];
				}
				
				
			}
		}
		b[i]=ans;
	}
	cout<<b[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
