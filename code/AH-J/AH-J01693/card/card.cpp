#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],p[N],cs[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		queue<int>q;
		for(int j=i;j<=n;j++)
		{
			if(p[a[j]]!=1)
			{
				q.push(a[j]);
				p[a[j]]=1;
			}
			else
			{
				for(;;)
				{
					int t=q.front();
					p[t]=0;
					q.pop();
					if(t==a[j]) break;
				}
			}
		}
		for(int i=1;i<=m;i++) if(p[i]==1) cs[p[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<cs[i]<<' ';
	return 0;
} 
