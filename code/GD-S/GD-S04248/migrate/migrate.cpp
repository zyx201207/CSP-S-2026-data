#include<bits/stdc++.h>
using namespace std;
//#define ll long long
//#define MAXN 2147483647
int c,t,n,d,x[114514],v,dfa,dft,ans;
int tapv[114514];
void dfs(int xl)
{
	if(xl>dft)return;
	if(xl==dft){dfa++;return;}
	for(int i=xl+1;i<=tapv[xl];i++)
	{
		dfs(tapv[i]);
	}
	return;
}
void check(int l,int r)
{
	dfa=0,dft=r;
	dfs(l);
	if(dfa==2)ans++;
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int ttk=1;ttk<=t;ttk++)
	{
		ans=-1;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&x[i]);
		for(int i=1;i<=n;i++)
		{
			v=i;
			while(x[++v]<=x[i]+d&&v<=n);
			tapv[i]=v-1;
		}
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)check(i,j);
		printf("%d\n",ans);
	}
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
