#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[m];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=sizeof(a[i]);i++)
	{
		b[i]=a[i];
	}
	for(int i=0;i<sizeof(a[i]);i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[i]==b[j]||b[i]==b[j+i])
			{
				b[j]=-1;
			}
			else
			{
				c[b[j]-1]++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<c[i]-1<<" ";
	}
	
	return 0;
}
