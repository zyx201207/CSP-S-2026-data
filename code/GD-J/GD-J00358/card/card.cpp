#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	queue<int> card;
	queue<int> cardn;
	vector<int> pai(m);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		card.push(x);
	}
	vector<int> vis(m+1,-1);
	vector<int> last(m+1,-1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int ggb=card.front();
			cardn.push(ggb);
			card.pop();
			card.push(ggb);
		}
		for(int j=1;j<=i-1;j++)
		{
			cardn.pop();
		}
		vector<int> out(n-i+2);
		for(int j=1;j<=n-i+1;j++)
		{
			int x=cardn.front();
			out[j]=x;
			if(vis[x]==1)
			{
				for(int k=last[x];k<=j;k++)
				{
					vis[out[k]]=-1;
				}
			}
			else if(vis[x]==-1)
			{
				vis[x]=1;
			}
		}
		for(int j=1;j<=n-i+1;j++)
		{
			if(vis[j]==1)
			{
				pai[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<pai[i]<<' ';
	}
}
