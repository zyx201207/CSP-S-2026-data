#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5;
int n,m,a[N],eans[M],s[N],cnts,la[M],nxt[M],nowf[M];
//int t[4 * N];
//bool h[M],vis[N];
bool isA = 1;
//void change(int i,int l,int r,int id,int add)
//{
//	if (l == r)
//	{
//		t[l] += add;
//		return ;
//	}
//	int mid = l + (r - l) / 2;
//	if (id <= mid) change(i * 2,l,mid,id,add);
//	else change(i * 2 + 1,mid + 1,r,id,add);
//}
//int query(int i,int l,int r,int x,int y)
//{
//	if (x <= l && r <= y) return t[i];
//	int res = 0,mid = l + (r - l) / 2;
//	if (x <= mid) res += query(i * 2,l,mid,x,y);
//	if (y > mid) res += query(i * 2 + 1,mid + 1,r,x,y);
//	return res;
//}
int main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d",&a[i]);
		if (a[i - 1] > a[i]) isA = 0;
		nxt[i] = n + 1;
	}
	if (isA)
	{
		int ans[M] = {0};
		for (int i = 1; i <= n; i++) ans[a[i]] = i;
		for (int i = 1; i <= m; i++) printf("%d ",ans[i]);
		exit(0);
	}
	if (n * m <= 10000000)
	{
		int v[n + 1][m + 1],v1[n + 1][m + 1],now[n + 1] = {0},ans[M] = {0};
		int maxx[M] = {0};
		memset(v,0,sizeof(v));
		memset(v1,0,sizeof(v1));
		for (int i = n; i >= 1; i--)
		{
			for (int j = 1; j <= m; j++)
			{
				v1[i][j] = now[j];
				printf("%d ",v1[i][j]); 
			}
			printf("\n");
			now[a[i]] = i;
		}
		memset(now,0,sizeof(now));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				v[i][j] = now[j];
			}
			now[a[i]] = i;
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == j || !v1[now[i]][j]) continue;
				maxx[i] = max(maxx[i],v[now[i]][j]);
			}
		}
		for (int i = 1; i <= m; i++)
		{
			printf("%d ",now[i] - maxx[now[i]]);
		} 
		exit(0);
	}
	for (int i = 1; i <= m; i++) printf("1 ");
	return 0;
}
