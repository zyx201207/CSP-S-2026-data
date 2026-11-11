#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500100,maxm=300100;
int n,m;
int a[maxn];
int inq[maxn];
int ans[maxm];
stack<int>q;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(inq,0,sizeof(inq));
		for(int j=i;j<=n;j++)
		{
			if(inq[a[j]])
			{
				while(q.top()!=a[j])
				{
					inq[q.top()]=0;
					q.pop();
				}
			} 
			else
			{
				q.push(a[j]);
				inq[a[j]]=1;
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
