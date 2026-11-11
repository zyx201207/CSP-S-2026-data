#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define rf(i,a,b) for(int i=(a);i>=(b);i--)
#define pt printf
#define eb emplace_back
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define FRE(f) {auto u=freopen(f".in","r",stdin);auto v=freopen(f".out","w",stdout);}
#ifdef DB
void db(){}
void db(auto x,auto...y){cout<<x<<",";db(y...);}
#define Z(x...) {pt("\t%s = ",#x);db(x);pt("\n");}
#define ZZ(x,l,r) {pt("\t%s = ",#x);fr(IT,l,r)cout<<x[IT]<<",";pt("\n");}
#else
#define Z(...)
#define ZZ(...)
#endif
mt19937 gen(random_device{}());
int rnd(int l,int r){return gen()%(r-l+1)+l;}
#define int LL
const int M=5e5+10,N=500+10;
int c,n,m,d,Q,a[M];
vector<pii>vc[N],cv[M];
int f[N][N];
signed main(){
    FRE("subway");
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>c>>n>>m>>d>>Q;
    fr(i,1,m)cin>>a[i];
    fr(i,1,n){
        int k;
        cin>>k;
        fr(j,1,k){
            int u,w;
            cin>>u>>w;
            vc[i].eb(u,w);
            cv[u].eb(i,w);
        }
    }
    memset(f,0x3f,sizeof f);

    fr(i,1,n)f[i][i]=0;
    fr(i,1,n){
        for(pii P:vc[i]){int u=P.x,x=P.y;
            for(pii PP:cv[u]){int j=PP.x,y=PP.y;
                f[i][j]=min(f[i][j],x+y);
            }
        }
    }
    fr(k,1,n){
        fr(i,1,n)if(i!=k){
            fr(j,1,n)if(j!=k&&j!=i){
                int nw=f[i][k]+f[k][j];
                if(f[i][j]>nw){
                    f[i][j]=nw;
                }
            }
        }
    }

    fr(_,1,Q){
        int p,q;
        cin>>p>>q;
        int ans=LLONG_MAX;
        for(pii P:cv[p]){int i=P.x,x=P.y;
            for(pii PP:cv[q]){int j=PP.x,y=PP.y;
                // Z(x,f[i][j],y);
                ans=min(ans,x+f[i][j]+y);
            }
        }
        pt("%lld\n",ans+a[p]+a[q]);
    }
    return 0;
}