#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,D,Q,op,x,y,w[N],l[N],d[M][M];
struct Y{int x,t;}a[N][25];
struct X{
	int y,w;
	bool operator<(const X &o)const{return w>o.w;}
}; 
vector<X>G[M]; 
priority_queue<X>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>op;
		for(int j=1;j<=op;j++)
		{
			cin>>x>>y;
			a[x][++l[x]]={i,y};
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=l[i];j++)
		{
			for(int k=1;k<=l[i];k++)
			{
				d[a[i][j].x][a[i][k].x]=a[i][j].t+a[i][k].t;
				d[a[i][k].x][a[i][j].x]=a[i][j].t+a[i][k].t;
			}
		}
	}
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	while(Q--)
	{
		cin>>x>>y;
		int ret=1e18;
		for(int i=1;i<=l[x];i++)
		{
			for(int j=1;j<=l[y];j++)
			{
				int sum=d[a[x][i].x][a[y][j].x]+a[x][i].t+a[y][j].t;
				ret=min(ret,sum);
			}
		}
		cout<<w[x]+w[y]+ret<<endl; 
	}
	return 0;
}
