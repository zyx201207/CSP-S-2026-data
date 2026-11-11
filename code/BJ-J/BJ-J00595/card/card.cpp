#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],lst[M],nxt[M],d[M],ans[M];
void topu()
{
	queue<int> q;
	for(int i=1;i<=m;i++)
	{
		if(d[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(nxt[u]==0)continue;
		d[nxt[u]]--;
		ans[nxt[u]]+=ans[u];
		if(d[nxt[u]]==0) q.push(nxt[u]);
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],lst[a[i]]=i;
	for(int i=1;i<=m;i++) nxt[i]=a[lst[i]+1],d[a[lst[i]+1]]++;
	for(int i=1;i<=n;i++) ans[a[i]]++;
	topu();
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
