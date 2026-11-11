#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N],maxid,eans;
bool vis[N][35],is[N],ans[35];
void suan(int x,int idx)
{ 
	int nowidx = 0;
	while (x)
	{
		vis[idx][++nowidx] = x % 2;
		x /= 2;
	}
	maxid = max(maxid,nowidx);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d",&a[i]);
		suan(a[i],i);
	}
	for (int i = maxid; i >= 1; i--)
	{
		int nowsum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!is[j]) nowsum += vis[j][i]; 
		}
		if (nowsum < m) continue;
		ans[i] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j][i]) is[j] = 1;
		}
	}
	for (int i = maxid; i >= 1; i--)
	{
		eans = eans * 2 + ans[i];
	}
	printf("%d",eans);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
