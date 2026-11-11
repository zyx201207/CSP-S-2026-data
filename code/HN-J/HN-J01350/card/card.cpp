#include<bits/stdc++.h>
using namespace std;
long long n,sum,tot,m,TOP;
long long l1,r1;
char x;
long long a[2000001],ans[2000001],zhan[2000001];
bool k[2000001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		TOP=0;
		for(int j=i;j<=n;j++)
		{
			if(k[a[j]]==0)
			{
				k[a[j]]=1;
				zhan[++TOP]=a[j];
			}
			else
			{
				while(zhan[TOP]!=a[j])
				{
					k[a[TOP]]=0;
					TOP--;
				}
			}
		}
		while(TOP!=0)
		{
			k[zhan[TOP]]=0;
			ans[zhan[TOP]]++;
			TOP--;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
