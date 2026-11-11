#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-')f=-1;ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(long long x){ if(x<0){ putchar('-');x=-x; }char c[23];int cnt=0;do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); } }
const int N=500005;
int n,w[N],m,d,q;
struct node{
	int to,val;
};
vector<node> e[N];
long long dis[505][505];
inline long long min(const long long a,const long long b){ return (a<b?a:b); }
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	n=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){ w[i]=read(); }
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			e[a].emplace_back((node){i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int k=e[i].size();
		for(int l=0;l<k;l++)for(int r=l+1;r<k;r++){ int u=e[i][l].to,v=e[i][r].to,len=e[i][l].val+e[i][r].val;dis[u][v]=dis[v][u]=min(dis[u][v],1ll*len); }
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
	while(q--){
		int x=read(),y=read();long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:e[x])for(auto j:e[y])ans=min(ans,dis[i.to][j.to]+i.val+j.val);
		write(ans+w[x]+w[y]);puts("");
	}
	return 0;
}
