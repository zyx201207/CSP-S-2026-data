#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
int sid,n,m,D,q,head[M],Next[M],ver[M],tot=0,Dig[N];
ll val[M],w[M],a[N][N];
void insert(int x,int y,ll z){
	ver[++tot]=y,val[tot]=z,Next[tot]=head[x],head[x]=tot;
}
int read(){
	int x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
void write(ll x,char ch){
	int c=0;
	while(x)Dig[++c]=x%10,x/=10;
	if(!c)putchar('0');
	while(c)putchar(Dig[c--]+'0');
	putchar(ch);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sid=read(),n=read(),m=read(),D=read(),q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j)a[i][j]=1e18;
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			int x=read();
			ll t=read();
			for(int l=head[x];l;l=Next[l]){
				int y=ver[l];
				if(i!=y)a[i][y]=a[y][i]=min(a[i][y],t+val[l]);
			}
			insert(x,i,t);
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)a[i][j]=min(a[i][j],a[i][k]+a[j][k]);
	while(q--){
		int x=read(),y=read();
		ll ans=2e18;
		for(int i=head[x];i;i=Next[i])
			for(int j=head[y];j;j=Next[j]){
				int u=ver[i],v=ver[j];
				ans=min(ans,a[u][v]+val[i]+val[j]);
			}
		write(ans+w[x]+w[y],'\n');
	}
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
