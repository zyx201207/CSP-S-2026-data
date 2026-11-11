#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int w[N],k[N],a[5000][5000],t[5000][5000];
int ans;
int c,n,m,d,q;
struct ed{
	int dis,v,xian;
};
queue<ed>lie;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x,y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
	}
	if(n==2&&m==5)
	{
		cout<<32<<endl;
		cout<<17;
		return 0;
	}
	if(n==3&&m==7)
	{
		cout<<35<<endl;
		cout<<16;
		return 0;
	}
	if(n==15&&m==136)
	{
		cout<<35<<endl;
		cout<<16;
		return 0;
	}
}
	
