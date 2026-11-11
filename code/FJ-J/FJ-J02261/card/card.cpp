#include<iostream>
#include<cstring>
using namespace std;
int x[500000+5][300000+5];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[500000+5];
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(x[i][a[j]]==0)
			{
				x[i][a[j]]=j;
			}
			else
			{
				for(int k=x[i][a[j]];k<=j;k++)
				{
					x[i][k]=0;
				}
				x[i][a[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int s=0;
		for(int j=1;j<=n;j++)
		{
			if(x[j][i]>0)
				s++;
		}
		cout<<s<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

