#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],st[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool A=0;
	for(int i=n;i>=1;i--) cin>>a[i];
	for(int i=2;i<=n;i++) if(a[i-1]<a[i]) A=0;
	if(A)
	{
		for(int i=n-1;i>=0;i--)
			if(i!=i+1) cout<<i+1<<" ";
	}
	else
	{
	queue<int> q,p;
	for(int i=1;i<=n;i++)
	{
		while(q.size())
		{
			int u=q.front();
			q.pop();
			if(u==a[i]) break;
			st[u]++;
			p.push(a[i]);
		}
		p.push(a[i]);
		q=p;
	}
	for(int i=1;i<=m;i++) cout<<st[i]+1<<" ";
	}
	return 0;
}
