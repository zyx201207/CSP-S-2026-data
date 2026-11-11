#include<iostream>
using namespace std;
int n,m,c[500050],a[500050];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	c[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int jj=j;
			while(jj<n)
			{
				if(a[jj]==a[j])
				{
					for(int l=jj;l<n;l++)
					{
						c[l]=0;
					}
			    }
			}
		}
		int num=0;
		for(int p=0;p<n;p++)
		{
			if(c[p]==1 && a[p]==m)
			{
				num++;
			}
		}
		cout<<num<<' ';
	}
	return 0;
}
