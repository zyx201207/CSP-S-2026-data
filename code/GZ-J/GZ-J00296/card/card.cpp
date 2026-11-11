//GZ-J00296，贵阳市南明区李端棻中学，任柏翰 
#include<bits/stdc++.h>
using namespace std;   

const int N=5*1e5+5;
const int M=3*1e5+5;
int n,m,ans;
int a[N];
int vis[M];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<int> cnt(m+5,0);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
				memset(vis,0,sizeof(vis));
			vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			cnt[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	
	return 0;
}
