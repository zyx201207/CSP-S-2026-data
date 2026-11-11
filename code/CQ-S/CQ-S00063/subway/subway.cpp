#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=5e5+10;
inline int readInt(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline ll readll(){
	char c=getchar();ll x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1ll;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10ll+c-'0';c=getchar();}
	return x*f;
}
int C,n,m,u,q,x,y,sta1,t1,k,w[N],a[510][N];
vector<int>b[510],v[N];
bool c[510][N],e[N];
ll dfs(int st,ll allt){
	ll Min=LONG_LONG_MAX;
	for(auto i:v[st]){
//		if(x==1&&y==2) printf("%d %d\n",a[i][st],a[i][y]);
		if(c[i][y]) return allt+a[i][st]+a[i][y];
		for(int o=0;o<b[i].size();o++){
			if(!e[b[i][o]]){
				e[b[i][o]]=1;
				Min=min(Min,dfs(b[i][o],allt+a[i][st]+a[i][b[i][o]]));
				e[b[i][o]]=0;
			}
		}
	}
	return Min;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway1.in","r",stdin);
	C=readInt(),n=readInt(),m=readInt(),u=readInt(),q=readInt();
	for(int i=1;i<=m;i++) w[i]=readInt();
	for(int i=1;i<=n;i++){
		k=readInt();
		for(int j=1;j<=k;j++){
			sta1=readInt(),t1=readInt();
			a[i][sta1]=t1;
			c[i][sta1]=1;
			v[sta1].push_back(i);
			if(v[sta1].size()==2) b[v[sta1][0]].push_back(sta1),b[v[sta1][1]].push_back(sta1);
			else if(v[sta1].size()>2) b[i].push_back(sta1);
		}
	}
	while(q--){
		x=readInt(),y=readInt();
//		ans[i]=w[x]+dfs(x,0)+w[y];
		printf("%lld\n",w[x]+dfs(x,0)+w[y]);
	}
//	printf("\n");
//	freopen("subway4.ans","r",stdin);
//	for(int i=1;i<=q;i++){
//		ll ok=readll();
//		if(ok!=ans[i]) printf("wa:%lld %lld\n",ok,ans[i]);
////		printf("%lld\n",readll());
//	}
	return 0;
}
