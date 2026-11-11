#include <bits/stdc++.h>
using namespace std;
struct node
{
	int num;
	int w;
};
node a[2000005];
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>d;
		for(int j=0;j<d;j++)
			a[j].w=1;
		for(int j=0;j<n;j++)
		{
			cin>>a[j].num;
			if(j>=d)
			{
				for(int k=j;k>=d;k--)
				{
					a[j].w+=a[k].w;
				}
			}
		}
	}
	return 0;
}
