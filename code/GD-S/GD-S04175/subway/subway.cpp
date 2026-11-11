#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=5e5+10;
int c,n,m,d,q,a[N];
struct node{
	int w,t;
}ls[N];
map<int,int> e[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			e[i][j]=(i==j?0:0x3f3f3f);
	for(int i=1,d;i<=n;i++)
	{
		cin>>d;
		for(int j=1;j<=d;j++)
			cin>>ls[j].w>>ls[j].t;
		for(int j=1;j<=d;j++)
			for(int k=1;k<j;k++)
				e[ls[j].w][ls[k].w]=e[ls[k].w][ls[j].w]=ls[j].t+ls[k].t;
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		cout<<a[x]+a[y]+e[x][y]<<"\n";
	}	
}
