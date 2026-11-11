#include<bits/stdc++.h>
using namespace std;
const long long N=500010,M=200010;
long long n,m,a[N],la[M],sl[M],r[M],v[M];
queue<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sl[a[i]]++;
		la[a[i]]=i;
	}
	for(long long i=1;i<=m;i++)
	{
		v[i]=a[la[i]+1];
		r[a[la[i]+1]]++;
	}
	for(long long i=1;i<=m;i++) if(!r[i]) q.push(i);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		r[v[now]]--;
		sl[v[now]]+=sl[now];
		if(!r[v[now]]) q.push(v[now]);
	}
	for(long long i=1;i<=m;i++) cout<<sl[i]<<' ';
	return 0;
}
