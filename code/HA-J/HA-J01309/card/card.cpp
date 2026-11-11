#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010],k;
int t[200010],q[200010];
bool vis[200010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
	    memcpy(b,a,sizeof(b));
		memset(t,0,sizeof t);
		k=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==false) 
			{
				t[a[j]]=1;
				k++;
				b[k]=a[j];
			}
			else
			{
				while(b[k]!=a[j])
				{
					k--;
					t[a[k]]=0;
				}
				k--;
				k++;
				b[k]=a[j]; 
				t[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(t[j]==1) q[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<q[i]<<" "; 
 } 
