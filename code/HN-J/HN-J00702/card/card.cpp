#include<bits/stdc++.h>
using namespace std;
struct node
{
	bool flag=0;
	int pos;
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100005];
	bool ans[100005];
	node g[100005];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int f[100005],sizee=0;
		for(int j=i;j<=n;j++)
		{
			if(g[a[j]].flag)
			{
				for(int k=g[a[j]].pos;k<=sizee;k++)  
				{
					f[k]=0;
					g[a[j]].flag=0;
				}
				sizee=g[a[j]].pos-1;
			}
			sizee++;
			g[a[j]].pos=sizee;
			g[a[j]].flag=1;
			f[sizee]=a[j];
			cout<<f[sizee]<<endl;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
