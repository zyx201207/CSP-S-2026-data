#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005];
int main()
{
freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			if(b[j]==1)
			{
				for(int k=j;k>=1;k--) b[k--];
			}
			b[j]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]) c[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
 } 
