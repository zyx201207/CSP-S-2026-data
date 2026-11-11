#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define f(x,y,z) for(int x=y;x<=z;x++)
#define g(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define ll long long
#define N 500005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
vector<int>id[N],tt[N];
ll dis[505][505];
int c,n,m,d,q,ls[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	f(i,1,m)ls[i]=read();
	f(i,1,n)f(j,1,n)dis[i][j]=1e18;
	f(i,1,n)dis[i][i]=0;
	f(i,1,n){
		int len=read();
		f(j,1,len){
			int u=read(),t=read();
			id[u].pb(i),tt[u].pb(t);
		}
	}
	f(u,1,m){
		int x1=id[u].size();
		f(i,1,x1)
			f(j,i+1,x1){
				int uu=id[u][i-1],vv=id[u][j-1];
				dis[uu][vv]=min((tt[u][i-1]+tt[u][j-1])*1ll,dis[uu][vv]);
			}
	}
	f(k,1,n)f(i,1,n)
		f(j,i+1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	f(i,1,n)f(j,1,i-1)dis[i][j]=dis[j][i];
	while(q--){
		int x=read(),y=read();
		ll ans=1e18;
		int x1=id[x].size(),x2=id[y].size();
		f(i,0,x1-1)
			f(j,0,x2-1){
				int u=id[x][i],v=id[y][j];
				ans=min(ans,dis[u][v]+tt[x][i]+tt[y][j]);
			}
		printf("%lld\n",ans+ls[x]+ls[y]);
	}
	return 0;
}