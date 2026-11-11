#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long e[100];
vector<int> vis[100];
vector<int> q;
int n,m,k;
long long ans=0;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x)
{
	k=-1;
	for(int i=x-1;i>=0;i--)
	{
		if(vis[i].size()>=m)
		{
			k=i;
			break;
		}
	}
	ans+=e[k];
	if(k==0 || k==-1) return ;
	q.clear();
	for(int i=0;i<vis[k].size();i++)
	{
		q.push_back(vis[k][i]);
	}
	for(int i=0;i<=30;i++)
	{
		vis[i].clear();
	}
	for(int i=0;i<q.size();i++)
	{
		int x=a[q[i]];
		for(int j=30;j>=0;j--)
		{
			if(x>=e[j])
			{
				x-=e[j];
				vis[j].push_back(q[i]);
			}
		}
	}
	dfs(k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	e[0]=1;
	for(int i=1;i<=30;i++)
	{
		e[i]=e[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i];
		for(int j=30;j>=0;j--)
		{
			if(x>=e[j])
			{
				x-=e[j];
				vis[j].push_back(i);
			}
		}
	}
	dfs(31);
	cout<<ans;
	return 0;
}
