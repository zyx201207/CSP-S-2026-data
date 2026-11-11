#include<bits/stdc++.h>
using namespace std;
const int M=200005;
long long n,m;
int b[M];
int a[M],maxn=-1e8;
void dfs(int pos,int sum,int k)
{
	if(pos==m)
	{
		maxn=max(maxn,sum);
		return;
	}
	for(int i=k+1;i<=n;i++)
	{
		if(b[i]==1)continue;
		b[i]=1;
		if(pos==0)
		{
			dfs(pos++,a[i],i);
		}
		else 
		{
			dfs(pos++,(sum&a[i]),i);
		}
		b[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0);
	cout<<maxn;
	return 0;
}
