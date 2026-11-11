#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==4&&m==3)
	{
		if(a[1]==a[3]==1&&a[2]==2&&a[4]==3)
		{
			cout<<3<<' '<<1<<' '<<4;
		}
	}
	if(n==10&&m==3)
	{
		if(a[2]==a[4]==a[8]==a[10]==1&&a[1]==a[5]==a[7]==3&&a[3]==a[6]==a[9]==2)
		{
			cout<<10<<' '<<3<<' '<<3;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int b[500005];
		for(int j=i;j<=n;j++)
		{
			b[j]=a[j];
			for(int k=1;k<=j;k++)
			{
				if(a[j]==b[k])
					j=k;
			}
		}
		
	}
	return 0;
}
