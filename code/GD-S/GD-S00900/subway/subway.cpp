#include<bits/stdc++.h> 
#define int long long
#define mem(a) memset(a,0,sizeof(a))
#define size(s) ((int)(s.size()))

using namespace std;

bool ppp;

const int N=5e5+5,M=505,inf=1e18;

struct gg{
	int u,l;
};

long long n,m,d,q,w[N],f[M][M];
vector<gg> e[N];
gg pp[25],qq[25];

bool qqq;

signed main(){
//	cerr<<((&ppp)-(&qqq))/1048576.0<<"\n";
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) f[i][j]=inf;
	for(int i=1;i<=m;i++){
		int tt=0;
		for(auto u:e[i]) tt++,pp[tt]=qq[tt]=u;
		for(int x=1;x<=tt;x++) for(int y=1;y<=tt;y++) if(x!=y){
			f[pp[x].u][qq[y].u]=min(f[pp[x].u][qq[y].u],pp[x].l+qq[y].l);
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int pl=0,ql=0;
		for(auto u:e[x]) pp[++pl]=u;
		for(auto u:e[y]) qq[++ql]=u;
		int ans=inf;
		for(int x=1;x<=pl;x++) for(int y=1;y<=ql;y++) ans=min(ans,f[pp[x].u][qq[y].u]+pp[x].l+qq[y].l);
		cout<<ans+w[x]+w[y]<<"\n";
	}
}


