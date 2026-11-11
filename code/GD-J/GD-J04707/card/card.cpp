#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long n,m,a[N],d[N],r[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(r,0,sizeof(r));
		for(int j=i;j<=n;j++)
		{
			if(r[a[j]]==1)
			{
				for(int k=j;k>=i;k--)
				{
					r[a[k]]=0;
					if(a[k]==j)break;
				}
			}
			r[a[j]]=1;
		}
		for(int j=1;j<=m;j++)d[j]+=r[j];
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
}
