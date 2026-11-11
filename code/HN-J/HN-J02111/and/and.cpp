#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int n,m;
long long aa[N],ans[N],maxx;
void dfs(int x,long long val,int time)
{
	if(time==m)
	{
		maxx=max(maxx,val);
		return;
	}
	if(x>n)
	{
		return;
	}
	val=val&aa[x];
	for(int i=1;x+i<=n;i++)
	{
		dfs(x+i,val,time+1);
	}
	return;
}
int main()
{
	//freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,aa[i],0);
	}
	cout<<maxx;
	return 0;
}/*
5 3
31 3 1 15 7
4 2
3 15 12 12
*/
