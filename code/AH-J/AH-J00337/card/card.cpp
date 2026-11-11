# include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n,m;
int a[N],k[N],f[N],ans[N];
int find(int x)
{
	return k[x] == 0 ? x : (k[x] = find(k[x]));
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d",&a[i]);
		if (f[a[i]]) k[f[a[i]]] = i;
		f[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) 
		if (k[i] != 0)k[i] = find(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			ans[a[j]]++;			
			if (k[j]) 
				j = k[j];				
		}
	}
	for (int i = 1; i <= m; i++) printf("%d ",ans[i]);
    return 0;
}
