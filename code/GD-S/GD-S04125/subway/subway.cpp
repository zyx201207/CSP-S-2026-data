#include<bits/stdc++.h> 
using namespace std;
int p[10000000],k[10000000],fa[10000000];
vector<pair<int,int>>a[100000],t[100000];
int sum=0;
int a_a(int x,int y)
{
	if(qvq(x)!=qvq(y))
		fa[x]=fa[y]; 
}
int qvq(int x)
{
	return fa[x]==x? x:qvq(fa[x])=x;
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=m;i++)
	{
		fai]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int c=i;
		cin>>k[i];
		for(int j=1;<=2*k[i];j++)
		{
			int q1,q2;
			cin>>q1>>>q2;
			a[i]_push_back(j,q1);
			a[j]_push_back(i,q1); 
			a[i]_push_back(j,q2);
			a[j]_push_back(i,q2);
			a_a(q1,c);
			c=q1;
			  
		} 
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		sum+=p[x]+p[y];
		if(qvq[x]==qvq[y])
		{
			sum=sum+ t[][x]+t[][y];
		}

	}
	return 0;
}
