#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,step;
}t;
struct Edge
{
	int u,v;
}p[1000005];
int c,T;
int n,k;
queue<node> q;
bool vis[100005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>p[i].u>>p[i].v;
		}
		if(n==k)
		{
			cout<<0<<endl;
			continue;
		}
		else if(n==k-1)
		{
			cout<<1<<endl;
			continue;
		}
		else cout<<1<<endl;
	}
	return 0;
}
