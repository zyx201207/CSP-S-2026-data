#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
typedef long ll;
const ll INF = 0x3f3f3f3f3f3f;
const int N = 505;
const int M = 500005;

ll read(){
	ll k = 0,f=1;char c = getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())k=(k<<1)+(k<<3)+(c^48);
	return k*f;
}

ll c,n,m,d,q;
ll G[N][N];
ll w[M],t[M][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i = 1;i<=m;i++)w[i] = read();
	for(int i = 1;i<=n;i++){
		int K = read();
		while(K--){
			int a = read();
			t[a][i] = read();
		}
	}
	memset(G,0x3f,sizeof(G));
	for(int i = 1;i<=n;i++)G[i][i] = 0;
	for(int i = 1;i<=m;i++){
		for(int j =1;j<=n;j++){
			if(t[i][j]==0)continue;
			for(int k = j+1;k<=n;k++){
				if(t[i][k]==0)continue;
				G[k][j] = G[j][k] = min(G[k][j],t[i][j]+t[i][k]);
			} 
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			printf("%d ",G[i][j]);
//		}
//		printf("\n");
//	}
	for(int k = 1;k<=n;k++){
		for(int i =1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	while(q--){
		ll x = read(),y=read(),ans = INF;
		for(int i = 1;i<=n;i++){
			if(t[x][i]==0)continue;
			for(int j = 1;j<=n;j++) {
				if(t[y][j]==0)continue;
				ans = min(ans,w[x]+w[y]+t[x][i]+t[y][j]+G[i][j]);
			}
		}
		printf("%lld\n",ans);
	} 
	//return 0;
}
