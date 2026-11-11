#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],c[1000005],d[1000005],e[1000005];
int main()
{
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n-i;j<=n;j++)
		{
			b[a[j]]++;
			for(int f=1;f<=n;f++)
			{
				if(d[f]==0){
					d[f]=a[j];
					break;
				}
			}
			if(b[a[j]]>1)
			{
				for(int k=1;k<=n;k++)
				{
					if(d[k]==a[j]){
						for(int l=k;l<=n;l++)
						{
							b[d[l]]--;
							d[l]=0;
						}
					}
					break;
				}	
			}
		}
		for(int g=1;g<=n;g++)
		{
			if(d[g]==0)break;
			c[d[g]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i]==0)
		{
			cout<<c[e[i]]<<" ";
			e[i]++;
		}
	}
	freopen("card.in","r",stdin);
	return 0;
}
