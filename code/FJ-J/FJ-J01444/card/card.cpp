#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
queue <int> q[300005];
struct node
{
	int l,r,id;
}p[300005];
bool cmp(node x,node y)
{
	return x.l < y.l;	
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		p[a[i]].id = a[i];
		if(p[a[i]].l == 0) p[i].l = i;
		else p[a[i]].r = i-1;
		q[a[i]].push(i);
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= m; )
		{
			sort(p+1,p+m+1,cmp);
			int id = p[i].id;
			while(p[i].l < k)
			{
				q[p[i].id].pop();
				p[i].l = q[id].front();
			}
			int j = 2;
			
			while(p[j].l < p[i].r && j <= m)
			{
				id = p[j].id;
				q[p[j].id].pop();
				p[j].l = q[id].front();
				if(p[j].l > p[i].r) j++;
			}
			for(int l = p[i].r+1;l <= p[j].l;l++)
				ans[a[l]]++;
			i = j;
		}
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i] << " ";
	return 0;
}
