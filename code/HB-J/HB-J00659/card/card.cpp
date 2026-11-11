#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[500005];
vector <int> book[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		book[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		book[a[i-1]].erase(book[a[i-1]].begin()+0);
		int ti=i;
		while(book[ti].size()-1>=0&&ti<=n)
		{
			int len=book[a[ti]].size();
			int nxt=book[a[ti]][len-1];
			ti=nxt+1;
		}
		for(int k=ti;k<=n;k++) ans[k]++;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}
