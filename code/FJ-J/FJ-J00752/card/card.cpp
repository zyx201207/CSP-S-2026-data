#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],pos[100005],num=0,vis[100505];
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
		if(vis[a[i]]==0)
		{
			vis[a[i]]++;
			b[i]=a[i];
			pos[a[i]]=i;
			num++;
		}
		else
		{
			for(int j=pos[a[i]];j<=num;j++)
			{
				b[j]=0;
				num--;
			}
			b[i]=a[i];
			num++;
		}
		cout<<b[i];
	}
}
