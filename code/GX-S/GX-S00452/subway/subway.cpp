#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<cstring>
#include<vector>
#define ll long long 
#define MARCH 500001
using namespace std;
ll read()
{
	char ch = 0;
	bool flag = 0 ;
	ll x = 0 ;
	while (ch > '9' || ch < '0')
	{
		ch = getchar();
		if (ch == '-')
			flag = 1 ;
	}
	while ('0' <= ch && ch <= '9')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();	
	}
	if(flag == 1)
		x = -x;
	return x ;
}
void write(ll x)
{
	if(x<0) {putchar('-');x=-x;}
	if(x<10) putchar(x+'0');
	if(x>=10) {write(x/10); putchar(x%10+'0');}
	return ;
}
ll c , n , m , d , Q ;
ll w[MARCH]; 
struct edge
{
	ll f,t,w,next;
/*
	const bool operator > (w ,edge w)
	{
        return w<x.w ;
	}
*/
}e[MARCH*41];
ll head[MARCH],tot,dis[MARCH];
vector<ll>v;
bool vis[MARCH];
void add(ll f,ll t,ll w)
{
	e[++tot].f = f ;
	e[tot].t = t ;
	e[tot].w = w ;
	e[tot].next = head [f];
	head [f] = tot ;
}
//priority_queue<ll>q;// da gen dui 

void dijkstra(ll f,ll t)
{
	memset(dis, 127 , sizeof(dis));
	memset(v,0,sizeof(v));
	for(int i = head[f]; i ;i = e[i].next )
		v.push_back(i);
	while(!v.empty())
	{
		ll len = v.size(),minn=2147483647,iminn = 0 ;
		for(int i=1;i<=len-1;i++)
			if( e[ v[i] ].w > e[ minn ].w )
			minn = min( e[ v[i] ].w , e[ minn ].w ) ;
		vis[ e[ minn ].to ] = 1 ;
		swap()
	}	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	n=read();
	m=read();
	ll f,t,w;
	for(int i=m;i<=m;i++)
	{
		f= read();
		t= read();
		w= read();
		add(f,t,w);
		add(f,t,w);
	}
	f = read(); t = read();
	dijkstra(f,t);
	return 0;
}
