#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
struct way{
	int s[25];long long t[25],cnt;
}S[500005];
long long G[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&arr[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a;long long t;
			scanf("%d%lld",&a,&t);
			S[a].s[++S[a].cnt]=i;
			S[a].t[S[a].cnt]=t;
		}
	}
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=n;i++)G[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int u=1;u<=S[i].cnt;u++){
			for(int v=u+1;v<=S[i].cnt;v++){
				int x=S[i].s[u],y=S[i].s[v];
				G[x][y]=G[y][x]=S[i].t[u]+S[i].t[v];
			}
		}
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][mid]+G[mid][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		scanf("%d%d",&st,&ed);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int u=1;u<=S[st].cnt;u++){
			for(int v=1;v<=S[ed].cnt;v++){
				int x=S[st].s[u],y=S[ed].s[v];
				ans=min(min(G[x][y]+arr[st]+arr[ed]+S[st].t[u]+S[ed].t[v],G[y][x]+arr[st]+arr[ed]+S[st].t[u]+S[ed].t[v]),ans);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
