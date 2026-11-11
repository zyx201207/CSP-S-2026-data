#include <iostream>
#include <cstring>
using namespace std;

const int N=1e3+10,M=5e5+10;
int c,n,m,d,q,k; //分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过
int v[M],w[M];
int a[N][N],t[N][N];
int h[N],e[N],wi[N],ne[N],idx;

void add(int a,int b,int c)
{
	e[idx]=b;
	wi[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(h,-1,sizeof h);
	int p1=0,p2=0;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++) scanf("%d",&w[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;i<k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(p1!=0) add(p1,x,p2),add(x,p1,p2);
			a[i][j]=x;t[i][j]=y;
			p1=x;p2=y;
		}
	}
	
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		int t1=l;
		for(int i=h[t1];i!=-1;i=ne[i])
		{
			int j=e[i];
			int h=wi[l]+wi[r];
			if(h>wi[j]) h=wi[j];
		}
		printf("%d",h);
	}
	return 0;
}
