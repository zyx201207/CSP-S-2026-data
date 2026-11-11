#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cs[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int b[500005]={0},s=i-1,f[500005]={0};
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0) 
			{
				s++;
				b[s]=a[j];
				f[a[j]]=j;
			}
			else
			{
				int y=s;
				s=f[a[j]];
				for(int k=s+1;k<=y;k++)
				{
					f[a[k]]=0;
					b[k]=0; 
				} 
			}
		}
		for(int j=i;j<=s;j++)
		{
			cs[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cs[i]<<" ";
	}
	
	return 0;
}  
