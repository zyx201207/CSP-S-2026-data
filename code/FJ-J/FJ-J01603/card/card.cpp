#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],b[M];
bool vis1[M],vis2[M];
queue<int> q;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis2,0,sizeof(vis2));
		for(int j=i;j<=n;j++)
		{
			if(vis2[a[j]])
			{
				memset(vis1,0,sizeof(vis1));
				while(true)
				{
					if(q.front()==a[j])
					{
						break;
					}
					int t=q.front();
					vis1[t]=1;
					q.pop();
					q.push(t);
				}
				if(q.front()==a[j])
				{		
					while(!q.empty())
					{
						if(vis1[q.front()])
						{
							break;
						}
						q.pop();
					}
				}
				vis2[a[j]]=0;
			}
			q.push(a[j]);
			vis2[a[j]]=1;
		}
		while(!q.empty())
		{
			b[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}





	return 0;
}

