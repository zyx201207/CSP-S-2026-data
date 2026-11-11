#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+5;
int n,m;
int a[MAX],cnt,b[MAX],c[MAX],d[MAX];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)c[i]=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]!=-1)
			{
				for(int q=c[a[j]]+1;q<=j;q++)c[a[q]]=-1;
			}
			else 
			{
				c[a[j]]=j;
			}
		}
		for(int q=i;q<=n;q++)
		{
			if(c[a[q]]!=-1)d[a[q]]++;
			c[a[q]]=-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
