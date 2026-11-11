#include <iostream>
#include <string>
#define int long long
using namespace std;
int n,m,a[200005],s[50][200005],b[200005],c[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int num=a[i],now=0;
		while(num!=0)
		{
			s[++now][i]=num%2;
			num/=2;
		}
	}
	for(int i=31;i>=1;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
			if(s[i][j]==1)
				b[++sum]=j;
		if(sum>=m)
		{
			for(int j=i-1;j>=1;j--)
			{
				int sum2=0;
				for(int k=1;k<=sum;k++)
					if(s[j][b[k]]==1)
						c[++sum2]=b[k];
				if(sum2>=m)
				{
					for(int k=1;k<=sum2;k++)
						b[k]=c[k];
					sum=sum2;
				}
			}
			int ans=a[b[1]];
			for(int j=2;j<=m;j++)
				ans&=a[b[j]];
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
