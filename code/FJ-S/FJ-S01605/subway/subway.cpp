#include<bits/stdc++.h>
#define mk mkae_pair
#define fir first
#define sec second
using namespace std;

inline int read(){char ch=getchar();int xxx=0,yyy=1;
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}
void write(long long x){
	if(x>=10)write(x/10);
	putchar('0'+x%10);
}
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=505,maxm=500005,maxd=21;
const ll inf=0x3f3f3f3f3f3f3f3f;

int n,m,d,q;
ll dis[maxn][maxn];
ll w[maxm];
int rd[maxm][maxd],cnt[maxm];
ll val[maxm][maxd];
pii edge[maxd*maxm];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	read();
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=0,tmp;j<k;j++){
			tmp=read();
			rd[tmp][++cnt[tmp]]=i;
			val[tmp][cnt[tmp]]=read();
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			int x=rd[i][j];
			for(int k=1;k<=cnt[i];k++){
				int y=rd[i][k];
				dis[x][y]=min(dis[x][y],val[i][j]+val[i][k]);
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		x=read();y=read();
		ll ans=inf;
		for(int j=1;j<=cnt[x];j++){
			int s=rd[x][j];
			for(int k=1;k<=cnt[y];k++){
				int t=rd[y][k];
				ans=min(ans,val[x][j]+val[y][k]+dis[s][t]);
			}
		}
		ans+=w[x]+w[y];
		write(ans);putchar('\n');
	}
	return 0;
}
