#include<bits/stdc++.h>
using namespace std;
long long a[200001][31],b[31],d[200001],z;
int main()                   
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;                               
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		int y=0;
		while(x)
		{
			if(x&1)
			{
				a[i][y]++;
				b[y]++;
			}
			y++;
			x/=2;
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(b[i]>=m)
		{
			z+=pow(2,i);
			for(int l=1;l<=n;l++)
			{
				if(a[l][i]==0&&d[l]==0){
				for(int j=0;j<=i;j++)
				{
					b[j]-=a[l][j];
				}
				d[l]=1;
				}
			}
		}
	}
	cout<<z;
	return 0;
}
