#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,mx=-114514;
int b[N];
bool vis[N];
void dfs(int a,int x,int d)
{
	if(x==0)
	{
		memset(vis,false,sizeof(vis));
		mx=max(mx,d);
		return ;
	}
	for(int i=1;i<=n&&x>0;i++)
	{ 
		if(!vis[i])
		{
			d&=b[i];
			cout<<d<<"\n";
			vis[a]=true;
			dfs(a+1,x-1,d); 
			vis[a]=false;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(b+1,b+n+1);
	dfs(1,m-1,b[1]);
	cout<<mx;
	return 0;
}
/*
4 2
3 15 12 12
*/
