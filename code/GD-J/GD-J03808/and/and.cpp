#include<bits/stdc++.h>
using namespace std;
const long long N=1e5*2+5;
vector<long long> a(N,0);
vector<bool> vis(N,0);
long long n,m,b=INT_MIN;
void dfs(long long depth,long long best)
{
	if(depth>m)
	{
		b=max(b,best); return;
	}
	for(long long i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(depth+1,best&a[i]);
			vis[i]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	dfs(1,1024*1024-1);
	cout<<b;
}
