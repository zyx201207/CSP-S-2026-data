#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
const int maxn=502,maxm=5e5+5,maxd=20;
const ll lnf=1e18;
int C,n,m,d,q;
ll E[maxn][maxn];
int pf[maxm];
vector<pii> pe[maxm];
void Doru(){
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>pf[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u,w;j<=k;j++) cin>>u>>w,pe[u].eb(mkp(i,w));
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) (j!=i)&&(E[i][j]=lnf);
	for(int i=1;i<=m;i++){
		int ln=pe[i].size();
		for(int j=0;j<ln;j++) for(int k=j+1;k<ln;k++){
			pii qwq=pe[i][j],qaq=pe[i][k];
			int u=qwq.fi,v=qaq.fi;
			ll w=min(E[u][v],(ll)qwq.se+qaq.se);
			E[u][v]=E[v][u]=w;
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) E[i][j]=E[j][i]=min(E[i][j],E[i][k]+E[k][j]);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ll res=lnf;
		for(pii qwq:pe[x]) for(pii qaq:pe[y]) res=min(res,E[qwq.fi][qaq.fi]+qwq.se+qaq.se);
		cout<<res+pf[x]+pf[y]<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Doru();
	return 0;
}

