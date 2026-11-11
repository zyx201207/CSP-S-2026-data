#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7,MAXM=3e5+7;
int n,m;
int a[MAXN];
int cnt[MAXM];
bool vis[MAXM];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		stack<int> st;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			int k=a[j];
			if(vis[k]==0)
			{
				 st.push(k);
				 vis[k]=1;
			}
			else
			{
				while(!st.empty())
				{
					if(st.top()!=k)
					{
						vis[st.top()]=0;
						st.pop();
					 } 
					else if(st.top()==k)
					{
						st.pop();
						break;
					}
				}
				st.push(k);
				vis[k]=1;
			} 
		}
		while(!st.empty())
		{
			int k=st.top();
			cnt[k]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
