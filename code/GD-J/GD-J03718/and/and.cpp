#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll nb[200005],biao[25]={0},tns[35],maxs=0,n,m;
void dfs(ll v,int ls)
{
	if(ls==m)
	{
		if(v>maxs)
		{
			maxs=v;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(biao[i]==0)
		{
			biao[i]=1;
			dfs(v&nb[i],ls+1);
			biao[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>nb[i];
		}
		for(int i=1;i<=n;i++)
		{
			biao[i]=1;
			dfs(nb[i],1);
			biao[i]=0;
		}
		cout<<maxs;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>nb[i];
		}
		cout<<nb[n];
	}
	
	return 0;
}
/*
5 3
31 3 1 15 7
*/
