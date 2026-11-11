#include<bits/stdc++.h>
using namespace std;
struct way{
	int sumn;
	int u[505]={};
	int d[505]={};
	int v[505]={};
	long long t[505]={};
};
long long tmin;
long long c,n,m,d,q,w[500005],t=0;
bool vis[500005];
int x,y;
way a[505];
long long e[1005][1005];
void dfs(int x)
{
	if(x==y)
	{
		tmin=min(tmin,t);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].u[x])
		{
			t+=a[i].t[x];
			for(int j=1;j<=a[i].sumn;j++)
			{
				if(!vis[a[i].v[j]])
				{
					vis[a[i].v[j]]=1;
					t+=a[i].t[a[i].v[j]];
					long long p=a[i].t[a[i].v[j]];
					a[i].t[a[i].v[j]]=0;
	//				cout<<x<<"qu"<<a[i].v[j]<<"time"<<t<<' '<<tmin<<' '<<"lux"<<i<<endl;
					dfs(a[i].v[j]);
					a[i].t[a[i].v[j]]=p;
					t-=a[i].t[a[i].v[j]];
					vis[a[i].v[j]]=0;
//					cout<<a[i].v[j]<<"qu"<<x<<"time"<<t<<' '<<tmin<<' '<<"lux"<<i<<endl;
				}
			}
			t-=a[i].t[x];
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		a[i].sumn=x;
		for(int j=1;j<=x;j++)
		{
			cin>>y;
			a[i].u[y]=1;
			a[i].v[j]=y;
			cin>>a[i].t[y];
		}
	}
	while(q--)
	{
		tmin=1ll<<62;
		cin>>x>>y;
		vis[x]=1;
		t+=w[x];
		dfs(x);
		cout<<tmin+w[y]<<endl;
		vis[x]=0;
		t-=w[x];
	}
	return 0;
 } 
