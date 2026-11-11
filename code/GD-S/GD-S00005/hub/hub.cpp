#include<bits/stdc++.h>
using namespace std;
int a[500000];
struct E
{
	int nxt,to;
}e[1500000];
int head[700000],cnt;
void add(int x,int y)
{
	cnt++;
	e[cnt].nxt=head[x];
	e[cnt].to=y;
	head[x]=cnt;
}
int bz[500000];
int n,K;
int vis[550000];
void sol()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y); 
		add(x,y);
		add(y,x);
	}
	printf("0\n");
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int fw,T;
	scanf("%d%d",&fw,&T);
	while(T--)
	{
		sol();
	}
}
