#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int z=5e5+9;
int n,m,maxx;
int a[z];
map<int,int>book;
void dfs(int step,int dis,int u)
{
	if(step>=m) return ;
	if(dis>=n) return ;
	if(u>n) return ;
	for(int i=1;i<=m-step;i++)
	{
		book[a[u]+i]++;
		book[a[u]]--;
		maxx=max(maxx,book[a[u]+i]);
		dfs(step+i,dis+1,u+1);
		book[a[u]+i]--;
		book[a[u]]++;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		book[a[i]]++;
		maxx=max(maxx,book[a[i]]);
	}
	dfs(0,0,1);
	cout<<maxx;
	return 0;
}
/*
5 5 
1 2 4 8 9

*/

