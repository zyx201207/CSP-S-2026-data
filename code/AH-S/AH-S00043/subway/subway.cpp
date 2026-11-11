/*

cd ~/draft && ulimit -s 1048576 && g++ subway.cpp -std=c++14 -O2 -Wall -fsanitize=address,leak,undefined -o subway && ./subway

diff -b subway.out subway7.ans

*/
#include <bits/stdc++.h>
using namespace std;
#define upp(x,y,z) for(x=(y);x<=(z);x++)
#define low(x,y,z) for(x=(y);x>=(z);x--)
#define fs(x) fixed<<setprecision(x)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define line '\n'
const int ext=0xf; const int N=5e5+ext,M=5e2+ext; const int mod=998244353; const ll inf=0x3fffffffffffffff;
template<typename t0> void ckmax(t0 &x,t0 y){if(x<y){x=y;} }
template<typename t0> void ckmin(t0 &x,t0 y){if(x>y){x=y;} }
void code(); void io(); void perf(); int main(){io(); code(); perf(); return 0;}
bool mb;
int c,n,m,d,q,w[N]; ll ans,dis[M][M]; vector<pair<int,int> > p[N];
void code(){
    int i,j,k,l,s1,s2,x,y; cin>>c>>n>>m>>d>>q; upp(i,1,m){cin>>w[i];}
    upp(i,1,n){cin>>j; upp(k,1,j){cin>>x>>y; p[x].pb({i,y});} }
    fill(&dis[0][0],&dis[0][0]+M*M,inf); upp(i,1,n){dis[i][i]=0;}
    upp(i,1,m){
        j=p[i].size();
        upp(k,1,j)upp(l,1,j){
            if(k==l){continue;}
            ckmin(dis[p[i][k-1].fi][p[i][l-1].fi],(ll)p[i][k-1].se+p[i][l-1].se);
            ckmin(dis[p[i][l-1].fi][p[i][k-1].fi],(ll)p[i][k-1].se+p[i][l-1].se);
        }
    }
    upp(i,1,n)upp(j,1,n)upp(k,1,n){
        ckmin(dis[j][k],dis[j][i]+dis[i][k]);
    }
    while(q--){
        cin>>x>>y; s1=p[x].size(); s2=p[y].size(); ans=inf;
        upp(j,1,s1)upp(k,1,s2){
            ckmin(ans,dis[p[x][j-1].fi][p[y][k-1].fi]+p[x][j-1].se+p[y][k-1].se+w[x]+w[y]);
        }
        cout<<ans<<line;
    }
}
bool me;
void io(){
    freopen("subway.in","r",stdin); freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void perf(){
    // cerr<<"Time used:"<<fs(3)<<1.0*clock()/CLOCKS_PER_SEC<<"s."<<endl;
    // cerr<<"Memory used:"<<fs(3)<<abs(1.0*(&me-&mb)/1024.0/1024.0)<<"MB."<<endl;
}