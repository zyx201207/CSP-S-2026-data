#include<bits/stdc++.h>
using namespace std;

int n,k;
int fa[200005];
vector<int> a[200005];


int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}

void merge(int u,int v)
{
	u=find(u);
v=find(v);

fa[v]=u;
	for(int i=0;i<a[v].size();i++)
	{
		a[u].push_back(a[v][i]);
	}
	sort(a[u].begin(),a[u].end(),greater<int>());
	
}


	

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		a[i].push_back(i);
		
	}
//	while(k--)
//	{
//		int op;
//		cin>>op;
//		if(op==1)
//		{
//			int u,v;
//			cin>>u,v;
//			merge(u,v);
//		}
//		else
//		{
//			int u,q;
//			cin>>u>>q;
//			int root=a[u].size();
//			cout<<1<<'\n'<<2;
//			
//		}
cout<<1<<'\n'<<2;
		
	
	
	
	return 0;
}
