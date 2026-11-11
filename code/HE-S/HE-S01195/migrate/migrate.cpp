#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pb push_back

inline int read(){
  char c=getchar();int d=0,f=0;
  while(!isdigit(c)){
	if(c=='-') f=1;c=getchar();
  }while(isdigit(c)){
	d=d*10+c-'0';c=getchar();
  }return f?-d:d;
}
const int MN=2e6+10,N=5e3+10,INF=1e18;
int pos[MN],n,d,maxr[MN],dis[N][N],res[N][N];
void solve1(){
	if(n==1){
		printf("0\n");return;
	}
	int delta=pos[2]-pos[1];
	if(d<delta){
		printf("0\n");return;
	}
	int x=d/delta;
	if(x==1) printf("0\n");
	else printf("%lld\n",max(n-2*x+1,0ll));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++) pos[i]=read();
		for(int i=1;i<=n;i++){
			int l=i,r=n,mid=0;
			while(l<r){
				mid=(l+r+1)>>1;
				if(pos[mid]-pos[i]<=d) l=mid;
				else r=mid-1;
			}
			maxr[i]=l;
		}
		if(c==11||c==12){
			solve1();
			continue;
		}
		int ans=0;
		for(int u=n;u>=1;u--){
			for(int v=n;v>u;v--){
				dis[u][v]=INF;
				if(v<=maxr[u]) dis[u][v]=1,res[u][v]=1;
				else if(dis[maxr[u]][v]==INF){
					dis[u][v]=INF;
					res[u][v]=0;
				}else{
					dis[u][v]=dis[maxr[u]][v]+1;
					res[u][v]=res[maxr[u]][v];
					for(int i=u+1;i<min(maxr[u],u+3);i++){
						if(dis[i][v]+1==dis[u][v]) res[u][v]+=res[i][v];
					}
				}
				if(res[u][v]==2){
					ans++;
//					cerr << u << ' ' << v << ' ' << dis[u][v]<<'\n';
				}
			}
		}
		
		printf("%lld\n",ans);
	}
	
  return 0;
}
