#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[1000000],vis[1000000],k[1000000];
stack<long long> p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			if(!vis[a[i]])
			{
				p.push(a[i]);
				vis[a[i]]=true;
			}
			else
			{
				while(!p.empty()&&p.top()!=a[i])
				{
					vis[p.top()]=false;
					p.pop();
				}
				p.pop();
				p.push(a[i]);	
			}
			
		}
		while(!p.empty())
		{
			k[p.top()]++;
			vis[p.top()]=false;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<k[i]<<" ";
	return 0;
}
