#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,max_num=0;
int a[200005];
int f[200005];
void dfs(int s,int g)
{
	if(g==m)
	{
		max_num=max(max_num,s);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1) continue;
		f[i]=1;
		int s1=s&a[i];
		dfs(s1,g+1);
		f[i]=0;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i]=0;
	dfs((1LL<<31)-1,0);
	cout<<max_num;
	return 0;
}
