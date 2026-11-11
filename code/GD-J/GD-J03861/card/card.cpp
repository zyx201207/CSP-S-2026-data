#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+5;
int a[N];
bool b[N];
int tong[N];
stack<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=0;
		}
		for(int i=j;j<=n;j++)
		{
			if(b[i]!=1)
			{
				q.insert(a[i]);
				b[i]=1;
			}
			else
			{
				while(q.top()!=a[i])
				{
					q.pop();
				}
			}
		}
		while(!q.empty())
		{
			int x=q.top();
			tong[x]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(tong[i]!=0)
		{
			cout<<tong[i]<<" ";
		}
	}
	return 0;
}
