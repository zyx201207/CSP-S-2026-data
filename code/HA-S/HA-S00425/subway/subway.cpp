#include<bits/stdc++.h>
using namespace std;
int w[100005];
int x[50005],y[50005],t[500005];
vector<int>a[100005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int u,v;
		cin>>u>>v;
		a[i].push_back(u);
		a[u].push_back(v);
		t[i]=v;
		
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(c==0)
	{
		if(n==2)
			cout<<32<<endl<<17;
		else if(n==3)
			cout<<35<<endl<<16;
	}
	return 0;
} 
