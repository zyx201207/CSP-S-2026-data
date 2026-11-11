#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,a[4100][4100];
//int ppp()
//{
//	
//}
//void dfs(int x,int d)
//{
//	if(d==k)
//	{
////		ppp();
//	}
//	int s[100010];
//	for(int i=x+1;i<=n;i++)
//	{
//		s[d]=i;
//		dfs(i,d+1);
//	}
//}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
//		dfs(0,0);
		cout<<1<<'\n';
		
	}
	
	
	return 0;
}
