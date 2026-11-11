#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,long long>
using namespace std;
const int M=5e5+5,N=505;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,m,n,d,q;
int dis[M];
ll w[N][N];
vector<PII>id[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(w,0x3f,sizeof w);
	w[0][0]=0;
	for(int i=1;i<=m;i++)
		scanf("%d",&dis[i]);
	for(int i=1;i<=n;i++){
		w[i][i]=0;
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			scanf("%d%lld",&a,&t);
			if(id[a].size())
				for(PII h:id[a]){
					w[i][h.first]=min(w[i][h.first],h.second+t);
					w[h.first][i]=w[i][h.first];
				}
			id[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]); 
	while(q--){
		int x,y;
		ll ans=inf;
		scanf("%d%d",&x,&y);
		for(PII i:id[x])
			for(PII j:id[y]){
				ans=min(ans,w[i.first][j.first]+i.second+j.second);
			}
		ans+=dis[x]+dis[y];
		printf("%lld\n",ans);
	} 
	return 0;
}
