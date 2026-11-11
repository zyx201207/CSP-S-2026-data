#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define pb push_back 
#define mkp make_pair
#define fir first
#define sec second
using namespace std;
const int BUFSIZE=1<<20;
char ibuf[BUFSIZE],*Is=ibuf,*It=ibuf;
inline char gc(){if(Is==It)It=(Is=ibuf)+fread(ibuf,1,BUFSIZE,stdin);return Is==It?EOF:*Is++;}
inline int read(){
	int x=0,f=1;char c=gc();
	while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=gc();
	return x*f;
}
void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
const int N=505,M=5e5+5;
const ll INFL=1e18;
int c,n,m,d,q,w[M],cnt[N];
ll dis[N][N];
vector<pii>ve[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=INFL;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		cnt[i]=read();
		for(int j=1;j<=cnt[i];j++)ve[read()].eb(mkp(i,read()));
	}
	for(int i=1,len;i<=m;i++){
		len=ve[i].size();
		for(int i1=1;i1<len;i1++)for(int i2=0;i2<i1;i2++){
			int u=ve[i][i1].fir,v=ve[i][i2].fir,w1=ve[i][i1].sec,w2=ve[i][i2].sec;
			dis[u][v]=dis[v][u]=min(dis[u][v],1ll*w1+1ll*w2);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(i==j || i==k || j==k)continue;
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int i=1,u,v,lenu,lenv;i<=q;i++){
		u=read(),v=read(),lenu=ve[u].size(),lenv=ve[v].size();ll ans=INFL;
		for(int j=0;j<lenu;j++)for(int k=0;k<lenv;k++)ans=min(ans,1ll*ve[u][j].sec+1ll*ve[v][k].sec+dis[ve[u][j].fir][ve[v][k].fir]);
		write(ans+1ll*w[u]+1ll*w[v]),puts("");
	}
	return 0;
}
