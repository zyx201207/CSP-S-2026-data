#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,sum;
struct stop
{
	int w1,w2,f;
	stop*p;
};
vector<stop> v;
int how(int x,int y)
{
	stop*p;
	sum+=v[x].w1;
	while(*p!=v[y])
	{
		p=v[x].p;
		
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	v.resize(n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>v[i].w1;
	}
	for(int i=1;i<=m;i++)
	{
		int k,x1,y1,x2,y2;
		cin>>k>>x1>>y1>>x2>>y2;
		v[x1].p=&v[x2];
		v[x1].f=1;
		v[x1].w2=y1;
		v[x2].w2=y2;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cout<<how(x,y)<<"\n";
	}
	return 0;
}
