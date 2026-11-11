#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500001],tong[300001];
bool t[300001];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int>q;
		while(q.size())q.pop();
		for(int j=1;j<=m;j++)t[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]==0)
			{
				t[a[j]]=1;
				q.push(a[j]);
			}
			else while(q.top()!=a[j])
			{
				t[a[j]]=0;
				q.pop();
			}
		}
		while(q.size())
		{

			tong[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<' ';
	return 0;
} 
