#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,LL> PII;
int n,m,d,q,t;
int w[500010];
LL dist[510][510];
vector<PII> p[500010],e[510];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int i,_;cin>>_>>m>>n>>d>>q,t=n;
    for(i=1;i<=n;i++)cin>>w[i];
    memset(dist,0x3f,sizeof dist);
    for(i=1;i<=m;i++){
        int k;cin>>k;
        while(k--){
            int x,w;cin>>x>>w,t++;
            e[i].push_back({x,w}),p[x].push_back({i,w});
        }
    }memset(dist,0x3f,sizeof dist);
    for(i=1;i<=m;i++)
		for(PII a:e[i])
			for(PII b:p[a.x])dist[i][b.x]=min(dist[i][b.x],a.y+b.y);
			
	for(i=1;i<=m;i++)dist[i][i]=0;
	for(int k=1;k<=m;k++)
		for(i=1;i<=m;i++)
			for(int j=1;j<=m;j++)dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
	
    while(q--){
        int x,y;
        LL ans=1e18;cin>>x>>y;
        for(PII a:p[x])
			for(PII b:p[y])
				ans=min(ans,dist[a.x][b.x]+a.y+b.y);
				
		cout<<ans+w[x]+w[y]<<'\n';
    }
}
