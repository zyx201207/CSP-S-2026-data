#include<bits/stdc++.h>
using namespace std;
const int INF=-1;
int n,m,a[200100],memo[650000][3000]={0};
bool vis[10000][1000]={0};
int dfs(int now,int last)
{
	if(vis[now][last]) return memo[now][last];
	if(now>n||last<=0) return memo[now][last]=INF;
	int res=max(dfs(now+1,last),a[now]&dfs(now+1,last-1));
	vis[now][last]=1;
	return memo[now][last]=res;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d",dfs(1,m));
	return 0;
}
