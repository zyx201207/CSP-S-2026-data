#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int ans[300010];
int main()
{   
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		queue<int> q;
		for(int j=i;j<=n;j++)
		{
			if(j==i) q.push(a[i]);
			else
			{
				int cnt=0;
				int f=0;
				while(!q.empty())
				{
					if(q.front()==a[j]) 
					{
						f=1;
						q.pop();
					}
					if(f==1)
					{
						q.pop();
					}
					else
					{
						cnt++;
						b[cnt]=q.front();
						q.pop();
					}
				}
				for(int t=1;t<=cnt;t++)
				{
					q.push(b[t]);
					b[t]=0;
				}
				q.push(a[j]);
			}		
		}
		while(!q.empty())
		{
			int tt=q.front();
			q.pop();
			ans[tt]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}
