#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=5e5+5;
int a[N],b[N];
bool vis[N];
stack<int> stk;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int l=0;l<n;l++)
	{
		memset(vis,false,sizeof(vis));
		for(int i=l;i<n;i++)
		{
			if(!vis[a[i]])
			{
				stk.push(a[i]);
				vis[a[i]]=true;
			}
			else
			{
				for(;;)
				{
					if(stk.top()==a[i])
					{
						vis[stk.top()]=false;
						stk.pop();
						break;
					}
					vis[stk.top()]=false;
					stk.pop();
				}
				stk.push(a[i]);
				vis[a[i]]=true;
			}
		}
		
		while(!stk.empty())
		{
			b[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
