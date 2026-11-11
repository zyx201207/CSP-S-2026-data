#include <bits/stdc++.h>
using namespace std;
const int N = 300000+5;
const int M = 200000+5;
int T,n;
int a[M];
int vis[N];
int place[N];
int turn[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=T;i++)cin>>a[i];
	for(int i=1;i<=T;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=T;j++)
		{
			vis[a[j]]++;
			if(vis[a[j]]==2)
			{
				for(int k=place[a[j]];k<j;k++)
				{
					vis[a[k]]--;
				}
			}
			place[a[j]]=j;
		 }	
		 for(int j=1;j<=n;j++)
			if(vis[j]==1)turn[j]++;
	}
	for(int i=1;i<=n;i++)
		cout<<turn[i]<<' ';
	return 0;
}
