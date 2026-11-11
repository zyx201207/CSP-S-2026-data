# include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[200005];
bool vis[200005];

void DFS (int p,int sum)
{
	if (p > m)
	{
		ans = max(ans,sum);
		return ;
	}
	for (int i = 1;i <= n;i++)
		if (vis[i] == false)
		{
			vis[i] = true;
			DFS(p + 1,sum & a[i]);
			vis[i] = false;
		}
}

int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++)
	{
		vis[i] = true;
		DFS(1,a[i]);
		vis[i] = false;
	}
	printf("%d",ans);
	return 0;
}

