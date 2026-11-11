#inslude<iostream>
#inslude<string>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,y;
	cin>>n>>m;
	int a[n+1],b[m+1],k[m+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[1]=a[1];
	for (int i=1;i<=m;i==)
	{
		k[i]=0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<i;j++)
		{
			if(b[j]==a[i])
			{
				for(int l=j+1;l<=i;l++)
				{
					b[l]=0;
				}
				break;
			}
			else
			{
				y=0;
			}
		}
		if(y==0)
		{
			b[j]=a[i];
		}
		for(int j=1;b[j]==0;j++)
		{
			k[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<k[i]<<' ';
	}
	return 0;
}
