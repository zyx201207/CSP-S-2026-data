#include<bits/stdc++.h>
#define ll long long
#define pir pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=505,maxm=5e5+5;
const ll INF=1e18;

template<class T,class _T>
inline const void chkmin(T &x,_T y){
	x=(x<y?x:y);
}
template<class T>
inline const void rd(T &x){
	ll f=1,k=0; char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		k=(k<<3)+(k<<1)+ch-'0';
		ch=getchar();
	}
	x=k*f;
}

int a[maxm];
ll f[maxn][maxn];
vector<pir>vt[maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q; rd(C),rd(n),rd(m),rd(d),rd(q);
	for(int i=1;i<=m;i++) rd(a[i]);
	for(int i=1,len;i<=n;i++){
		rd(len);
		for(int j=1,x,y;j<=len;j++){
			rd(x),rd(y);
			vt[x].push_back(mkp(i,y)); 
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1,len,u,v;i<=m;i++){
		len=vt[i].size();
		for(int j=0;j<len;j++){
			u=vt[i][j].fi;
			for(int k=j+1;k<len;k++){
				v=vt[i][k].fi;
				chkmin(f[u][v],(ll)vt[i][j].se+vt[i][k].se);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[j][i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmin(f[i][j],f[i][k]+f[k][j]);
	int x,y; ll ans;
	while(q--){
		rd(x),rd(y);
		ans=INF;
		for(auto i:vt[x])
			for(auto j:vt[y])
				chkmin(ans,f[i.fi][j.fi]+i.se+j.se);
		printf("%lld\n",ans+a[x]+a[y]);
	}
	return 0;
}
