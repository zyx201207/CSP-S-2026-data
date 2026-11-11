#include<bits/stdc++.h>
using namespace std;
int read()//long long?
{
	char c=getchar();
	int fu=1,res=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') fu=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res*fu;
}
void write(int x)//long long?
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<=9)
	{
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
	return;
}
const int N=26;
int n,m,a[200005];
int cnt[(1<<(N+1))-1],e[(1<<(N+1))-1][2],tot=0,ans=(1<<(N+1))-1;
void build(int x)
{
	int u=0;
	for(int dep=1;dep<=N;dep++)
	{
		int t=(x>>(N-dep))&1;
		//cout<<t;
		if(!e[u][t]) e[u][t]=++tot;
		u=e[u][t];
		cnt[u]++;
	}
	return;
}
void dfs(int u,int x,int dep,int state)
{
	if(dep>N) return;
	//if(state==1) cout<<ans<<endl;
	if(cnt[e[u][1]]>=x)
	{
		dfs(e[u][1],m,dep+1,1);
		dfs(e[u][0],m,dep+1,0);
		return;
	}
	ans=ans&(ans-(1<<(N-dep)));
	dfs(e[u][1],m,dep+1,1);
	dfs(e[u][0],x-cnt[e[u][1]],dep+1,0);
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//write(123);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		//cout<<a[i]<<' ';
		build(a[i]);
		//cout<<endl;
	}
	dfs(0,m,0,0);
	write(ans);
	return 0;
}//4 2 3 15 12 12
