/*
4 3
1 2 1 3
*/
#include<bits/stdc++.h>
using namespace std;
int a[500010],lst[500010];
int ans[500010];
int n,m;
void find(int x)
{
	if(x==1)
	{
		ans[a[n]]++;
		return;
	}
	int fir=a[n-x+1];
	//cout<<x<<' '<<fir<<' ';
	//1 2 cout<<lst[fir]<<'\n';
	if(lst[fir]>=x)
	{
		ans[fir]++;
		find(x-1);
	}
	else
	{
		find(lst[fir]);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		lst[i]=-1;
	}
	for(int i=n;i>=1;i--)
	{
		if(lst[a[i]]==-1)
		{
			lst[a[i]]=n-i+1; 
		}
	}
	for(int i=1;i<=n;i++)
	{
		find(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
