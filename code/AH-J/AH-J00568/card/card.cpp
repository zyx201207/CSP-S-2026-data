#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],tt[300001];
bool f[300001];
stack<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				q.push(a[j]);
				f[a[j]]=1;
			}
			else
			{
				while(!q.empty())
				{
					if(q.top()==a[j]) f[a[j]]=0;
					q.pop();
					if(f[a[j]]==0) break;
				}
				q.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(!q.empty())
		{
			tt[q.top()]++;
			q.pop();
		}
		for(int j=1;j<=m;j++)
			f[j]=0;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",tt[i]);
	return 0;
}
/*
4 3
1 2 1 3 
*/

