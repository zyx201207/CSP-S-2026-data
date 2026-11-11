#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int n,m,x,p[35],ans,s[35];bool a[M][35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<=30;i++)p[i]=pow(2,i);
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=30;j>=0;j--)
		{
			if(x>=p[j])
			{
				s[j]++;
				a[i][j]=1;
				x-=p[j];
			}
		}		
	}
	for(int i=30;i>=0;i--)
		if(s[i]>=m)
		{
			ans+=p[i];
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0)
				{
					for(int l=0;l<=30;l++)
					{
						if(a[j][l]==1)s[l]--,a[j][l]=0;
					}
				}
			}
		}
	cout<<ans;
	return 0;
}
