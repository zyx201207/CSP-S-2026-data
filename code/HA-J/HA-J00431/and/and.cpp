#include<bits/stdc++.h>
using namespace std;
int n,m,k,mmax,sum;
long long a[200005],b[200004],h[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
		for(int i=1;i<=n;i++)
		{
			k=a[i];
			for(int j=1;j<=m;j++)
			{
				for(int v=1;v<=n;v++)
				{
					sum=k&a[v];
					if(sum>mmax)
					{
						mmax=sum;
					}
				}
			}
		}
		cout<<sum;
		return 0;
}
