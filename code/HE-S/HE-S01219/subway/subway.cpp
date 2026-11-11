#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,d,q,m,w[N];
int e[N],a,t[N][3],k,v=2e9+5;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	if(c==20||c==21){
		v=2e9+5;
		memset(e,-1,sizeof(e));
		scanf("%lld",&k);
		for(int i=1;i<=k;i++){
			scanf("%lld",&a);
			scanf("%lld",&t[a][0]);
			e[a]=0;
		}
		scanf("%lld",&k);
		for(int i=1;i<=k;i++){
			scanf("%lld",&a);
			scanf("%lld",&t[a][1]);
			if(e[a]==0){
				e[a]=2;
				v=min(v,t[a][1]+t[a][0]);
				t[a][2]=min(t[a][1],t[a][0]);
			}else{
				e[a]=1;
			}
		}
		while(q--){
			int x,y,ans;
			scanf("%lld%lld",&x,&y);
			if((e[x]==1&&e[y]==0)||(e[x]==0&&e[y]==1)){
				ans=w[x]+w[y]+t[x][e[x]]+t[y][e[y]]+v;
			}else{
				ans=w[x]+w[y]+t[x][min(e[x],e[y])]+t[y][min(e[x],e[y])];
			}
			printf("%lld\n",ans);
		}
	}
	if(c>=7&&c<=11){
		int f[m+5][m+5];
		int b,u;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=INT_MAX;
				if(i==j) f[i][i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&k);
			if(k==1){
				scanf("%lld%lld",&a,&b);
			}else{
				scanf("%lld%lld%lld%lld",&a,&u,&b,&v);
				f[b][a]=min(f[b][a],u+v);
				f[a][b]=min(f[a][b],u+v);
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		while(q--){
			int x,y;
			scanf("%lld%lld",&x,&y);
			int ans=f[x][y]+w[x]+w[y];
			printf("%lld\n",ans);
		}
	}
	return 0;
}

