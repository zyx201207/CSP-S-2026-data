#include<bits/stdc++.h>
#define siz(_) ((int)_.size())
#define pb emplace_back
#define mk make_pair
#define Pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=505,M=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int Cid,n,m,D,q;
ll d[N][N];
int w[M];
vector<Pii> v[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Cid=read();n=read();m=read();D=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		int x,y;
		while(k--){
			x=read();y=read();
			v[x].pb(i,y);
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++){
		int x,y;ll k;
		for(auto pr1:v[i]){
			for(auto pr2:v[i]){
				x=pr1.fi;y=pr2.fi;k=pr1.se+pr2.se;
				d[x][y]=d[y][x]=min(d[x][y],k);
			}
		}
	}
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	int x,y;
	while(q--){
		x=read();y=read();
		ll ans=inf,res=0;
		for(auto pr1:v[x]){
			for(auto pr2:v[y]){
				res=pr1.se+pr2.se+d[pr1.fi][pr2.fi];
				ans=min(ans,res);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}
