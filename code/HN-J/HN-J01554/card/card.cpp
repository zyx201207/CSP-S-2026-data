#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],d[500010],dp[500010],lst[300010];
vector<int>e[500010];
queue<int> q;
void tp_sort()
{
	q.push(0);
	while(!q.empty())
	{
		int now=q.front();
		if(now!=0) dp[now]++;
		q.pop();
		for(int i=0;i<e[now].size();i++)
		{
			int v=e[now][i];
			dp[v]+=dp[now];
			d[v]--;
			if(d[v]==0) q.push(v);
		}
	}
	return;
}
signed main()
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
	    e[lst[a[i]]].push_back(i);
	    d[i]++;
		lst[a[i]]=i;
	}
	for(int i=2;i<=n;i++) 
	{
		if(lst[a[i-1]]==i-1) 
		{
			e[i-1].push_back(i);
			d[i]++;
		}
	}
	tp_sort();
	for(int i=1;i<=m;i++) cout<<dp[lst[i]]<<" ";
}
/*
bububu T4 rang wo 1h AK de xiang fa pou mie la
bu gou 1.5h AK hai xing
*/
