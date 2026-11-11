#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,mans[300005],ch;
int vis[300005];
queue<int> q;
int main()
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
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				bool flag=0;
				int g=q.size();
				for(int s=1;s<=g;s++)
				{
					int k=q.front();
					if(k==a[j]&&!flag)
					{
						ch=k;
						q.pop();
						vis[k]=0;
						flag=1;
						continue;
					}
					if(!flag) 
					{
						q.pop();
						q.push(k);
					}
					else
					{
						q.pop();
						vis[k]=0;
					}
				}
				q.push(ch);
				vis[ch]=1;
			}
			else
			{
				q.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!q.empty())
		{
			int f=q.front();
			q.pop();
			mans[f]++;
			vis[f]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mans[i]<<" ";
	}
	return 0;
}
