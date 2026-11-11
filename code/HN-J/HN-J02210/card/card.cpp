#include<bits/stdc++.h>
using namespace std;
stack<int>q;
map<int,int>mp;
bool f[400000];
int a[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int T=1;T<=n;T++)
	{
		memset(f,false,sizeof(f));
		for(int i=T;i<=n;i++)
		{
			if(f[a[i]]==true)
			{
				while(!q.empty())
				{
					if(q.top()==a[i])
					{
						q.pop();
						break;
					}
					f[q.top()]=false;
					q.pop();
				}
				q.push(a[i]);
				f[q.top()]=true;
			}
			else
			{
				q.push(a[i]);
				f[a[i]]=true;
			}
		}
		while(!q.empty())
		{
			mp[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
	return 0;
 } 
