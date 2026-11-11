#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
const int M=5e5+10;
struct nod
{
	int v,w,ls;
} a[10000000];
int w[M];
int head[M],cnt=0;
long long  ju[M];
int dui[M],top=0;
void spfa(int x)
{
	top=0;
	memset(ju,62,sizeof(ju));
	ju[x]=0;
//	cout<<"**"<<ju[0]+ju[0];
	for(int i=head[x]; i; i=a[i].ls)
	{
//		Sleep(100);
//		cout<<a[i].v<<" "<<a[i].w<<endl;
		int v=a[i].v,w=a[i].w;
		if(ju[v]>ju[x]+w)
		{
//			cout<<1;
			ju[v]=ju[x]+w;
			top++;
			dui[top]=v;
		}
	}
	while(top>0)
	{
		int u=dui[top];
		top--;
		for(int i=head[u]; i; i=a[i].ls)
		{
			int v=a[i].v,w=a[i].w;
			if(ju[v]>ju[u]+w)
			{
				ju[v]=ju[u]+w;
				top++;
				dui[top]=v;
			}
		}
	}
	return;
}
void add(int u,int v,int w)
{
	cnt++;
	a[cnt].v=v;
	a[cnt].w=w;
	a[cnt].ls=head[u];
	head[u]=cnt;
	return;
}
int a1[M],b1[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	//dis
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
	{
		cin>>w[i];
	}
	for(int ii=1; ii<=n; ii++)
	{
		int k;
		cin>>k;
		for(int i=1; i<=k; i++)
		{
			cin>>a1[i]>>b1[i];
			for(int j=i-1; j>=1; j--)
			{
//				cout<<a1[i]<<"**"<<a1[j]<<endl;
					add(a1[i],a1[j],b1[i]+b1[j]);
					add(a1[j],a1[i],b1[i]+b1[j]);

			}
		}

	}
	for(int i=1; i<=q; i++)
	{
		int x,y;
		cin>>x>>y;
		spfa(x);
		long long ans=0;
		ans=ju[y];
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<endl;
	}

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
