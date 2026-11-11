#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],b[500005],p[500005];
vector<long long>v[500005];
void dfs(int x)
{
	b[x]=1;
	for(int i=v[x].size()-1;i>=0;i--)
	{
		dfs(v[x][i]);
		b[x]+=b[v[x][i]];
	} 
	p[a[x]]+=b[x];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[a[i]]=i;
	}
	for(int i=n;i>0;i--)
	{
		v[s[a[i]]+1].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=m;i++)
	{
		cout<<p[i]<<" ";
	}
	return 0;
}
