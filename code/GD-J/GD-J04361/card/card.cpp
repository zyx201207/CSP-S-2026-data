#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,a[N];int st[N],stt=0;
int vis[N];
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
		stt=0;
		for(int j=i;j<=n;j++)
		{
			int flag=0;
			for(int k=1;k<=stt;k++)
			{
				if(st[k]==a[j])
				{
					stt=k;
					flag=1;
					break;
				}
			}
			if(!flag)stt++;
			st[stt]=a[j];
		}
		for(int j=1;j<=stt;j++)
		{
			vis[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<vis[i]<<' ';
	}
	return 0;
}
