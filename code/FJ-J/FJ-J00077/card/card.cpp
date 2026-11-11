#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int pos=i,num=1,b[500005];
		while(pos<=n)
		{
			b[num]=a[pos];
			for(int j=1;j<num;j++)
			{
				if(b[j]==a[pos])
				{
					num=j;
				}
			}
			num++;
			pos++;
		}
		for(int j=1;j<num;j++)
		{
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
