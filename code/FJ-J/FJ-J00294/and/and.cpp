#include<bits/stdc++.h>
using namespace std;
long long maxn=-1,t=2147483247,m;
long long n,a[2000000];
void dfs(int x,int p)
{
	if(x==0)
	{
		maxn=max(maxn,t);
	}
	for(int i=p;i<=n;i++)
	{
		int tmp=t;
		t=t&a[i];
		dfs(x-1,i+1);
		t=tmp;
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	dfs(m,1);
	cout<<maxn<<'\n';
	return 0;
}

