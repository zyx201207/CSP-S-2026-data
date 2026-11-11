#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5+10, M = 3e5+10;

struct node
{
	ll id,c;
}a[N];
ll ans[M],cnt[M],nex[M];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i<= n; i++)
	{
		cin>>a[i].c;
		a[i].id = ++cnt[a[i].c];
	}
	for(int i = 1; i<= n; i++)
	{
		nex[a[i].c] = i;
	}
	
	for(int i = 1; i<= n; i++)
	{
		ans[a[i].c]++;
		int now = i;
		while(now < n && now)
		{
			int cur = nex[a[now].c];
			cur++;
			ans[a[cur].c]++;
			now = cur;
		}
	}
	
	for(int i = 1; i<= m; i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
