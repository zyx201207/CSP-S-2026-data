#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
int n,m,a[N],vis[N],b[N],ans[N];
stack<int>q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int idx=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				for(int k=1;k<=b[a[j]];k++)
				{
					q.pop();
					idx--;
				}
			}
			else
			{
				q.push(a[j]);
				vis[a[j]]=1;
				idx++;
				b[a[j]]=idx;
			}
		}
		for(int i=1;i<=idx;i++)
		{
			cout<<q.top()<<" ";
			ans[q.top()]++;
			q.pop();
		}
		memset(b,0,sizeof b);
		memset(vis,0,sizeof vis);
		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;	
} 
