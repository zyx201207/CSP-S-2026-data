#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define ll long long
#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define fi first
#define se second
using namespace std;

const int N=505,M=5e5+5;
const ll inf=1e18;
int cid;
int n,m,d,q;
ll w[M];
vl S[M],W[M];
ll ew[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

	cin>>cid>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n){
		int k;cin>>k;
		rep(j,1,k){
			int x,v;cin>>x>>v;
			S[x].pb(i);
			W[x].pb(v);
		}
	}
	rep(i,1,n)rep(j,1,n)ew[i][j]=inf;
	rep(i,1,n)ew[i][i]=0;
	rep(i,1,m){
		int l=(int)S[i].size();
		rep(x,0,l-1)rep(y,0,l-1){
			if(x==y)continue;
			int a=S[i][x],b=S[i][y];
			ew[a][b]=min(ew[a][b],W[i][y]+W[i][x]);
		}
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)ew[i][j]=min(ew[i][j],ew[i][k]+ew[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int lx=(int)S[x].size(),ly=(int)S[y].size();
		ll ans=inf;
		rep(i,0,lx-1)rep(j,0,ly-1){
			ans=min(ans,w[x]+W[x][i]+ew[S[x][i]][S[y][j]]+W[y][j]+w[y]);
		}
		cout<<ans<<'\n';
	}
    return 0;
}



//guanzhufalidamiao,xiexiemiao
