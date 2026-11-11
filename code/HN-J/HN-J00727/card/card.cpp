#include <iostream> 
#include <cstdio>
using namespace std;
int n,m,a[10],b[10],c[10];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
			b[j]=0;
		for(int j=i;j<n;j++)
			b[j]=a[j];
		for(int j=0;j<n;j++)
		{
			if(b[j]!=0)
			{
				for(int k=j+1;k<n;k++)
				{
					if(b[j]==b[k])
					{
						for(int l=j;l<k;l++)
							b[l]=0;
					}
				}
			}
		}
		for(int j=0;j<n;j++)
			if(b[j]!=0) c[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
