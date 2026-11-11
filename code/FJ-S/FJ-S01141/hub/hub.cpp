#include<bits/stdc++.h>
using namespace std;
const int N=20,inf=0x3f3f3f3f,MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
int h[N],p[N],t[N],cnt; 
void adde(int x,int y) {p[++cnt]=h[x];h[x]=cnt;t[cnt]=y;}
bitset<N>z,b;int n,k,e=inf,ww[N];
void ddfs(int x)
{
	b[x]=1;
	for(int o=h[x];o;o=p[o])
		if(z[t[o]] && !b[t[o]]) ddfs(t[o]);
}
void sv1()
{
	int zz=0;//cout<<"Dsv1"<<endl;
	for(int i=1;i<=n;i++)
		if(z[i]) zz++;
	if(zz!=k) return;
	zz=0;b=0;queue<int>q;
	for(int i=1;i<=n;i++)
		if(z[i] && !b[i]) zz++,ddfs(i);
	if(zz>2) return;
	b=0;int ppp=0;
	for(int i=1;i<=n;i++)
		if(z[i]) q.push(i),ww[i]=0,b[i]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int o=h[x];o;o=p[o])
			if(!b[t[o]]) q.push(t[o]),b[t[o]]=1,ww[t[o]]=ww[x]+1;
	}
	for(int i=1;i<=n;i++) ppp=max(ppp,ww[i]);
	e=min(e,ppp);
}
void dfs(int x)
{
	if(!x) {sv1();return;}
	dfs(x-1);z[x]=1;dfs(x-1);z[x]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;scanf("%d%d",&c,&T);
	if(c==13 || c==14)
	{
		while(T--)
		{
			scanf("%d%d",&n,&k);int a,b;
			for(int i=1;i<n;i++) scanf("%d%d",&a,&b);
			int m=n/2,lp=m/2,rp=m-lp,lk=k/2,rk=k-lk;
			if(k>=m && k<n) {puts("1");continue;}
			if(k==n) {puts("0");continue;}
			printf("%d\n",int(max(ceil((lp-lk)*0.5),ceil((rp-rk)*0.5)))+1);
		}
		return 0;
	}
	while(T--)
	{
		scanf("%d%d",&n,&k);int a,b;cnt=0;memset(h,0,sizeof(h));memset(p,0,sizeof(p));
		for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
		dfs(n);printf("%d\n",e);e=inf;
	}
	return 0;
}
//1 2 3 4 5
