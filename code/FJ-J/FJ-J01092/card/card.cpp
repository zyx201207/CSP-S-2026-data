#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int cnt[1000005];
bool  f[1000005];

queue<int> q;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		memset(f,0,sizeof(0));
		while(!q.empty())
		{
			cnt[q.front()]++;
			q.pop();
		}
		while(!q.empty())
		{
			q.pop();
		}
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=1;
				q.push(a[j]);
			} 
			else
			{
				while(!q.empty())
				{
					q.pop();
				}
			}
		}	
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
 } 
