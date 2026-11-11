#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[500005],ans[300005];
bool vis[300005],flag=1;
queue<int> q;
queue<int> qe;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0){q.push(a[j]);vis[a[j]]=1;}
			else
			{
				flag=1;
				while(!q.empty())
				{
					if(q.front()==a[j]) flag=0;					
					if(flag==1) qe.push(q.front());
					q.pop();				
				}
				while(!qe.empty())
				{
					q.push(qe.front());
					qe.pop();
				}
				q.push(a[j]);
			}
		}
		while(!q.empty())
		{
			int f=q.front();
			ans[f]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
