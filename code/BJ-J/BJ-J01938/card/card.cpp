#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int h[N];
int a[N];
int tab[N];
int ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(h,0,sizeof h);
		memset(tab,0,sizeof tab);
		int idx=0;
		for(int j=i;j<=n;j++)
		{
			if(h[a[j]]!=0)
			{
				if(h[a[j]]<=idx) idx=h[a[j]];
				else tab[++idx]=a[j],h[a[j]]=idx;
			}
			else tab[++idx]=a[j],h[a[j]]=idx;
		}
		for(int j=1;j<=idx;j++)
		{
			int x=tab[j];
			
			ans[x]++;
		}
		
	}
	for(int i=1;i<=m;i++) cout <<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
