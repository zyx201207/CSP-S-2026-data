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
const int N=20+5;
int n,k,C,T;
vector<int>eg[N];
int c[N],ci,z;
void color(int s){//color it
    static int q[N],hd,tl;
    hd=0,tl=-1;
    q[++tl]=s;
    c[s]=ci;
    while(hd<=tl){
        int u=q[hd++];
        for(int v:eg[u])if(z>>v-1&1){
            if(!c[v]){
                q[++tl]=v;
                c[v]=ci;
            }
        }
    }
}
int bfs(){
    static int q[N],hd,tl,d[N];
    hd=0,tl=-1;
    fr(i,1,n)d[i]=n+1;
    fr(i,1,n)if(z>>i-1&1){
        q[++tl]=i;
        d[i]=0;
    }
    while(hd<=tl){
        int u=q[hd++];
        for(int v:eg[u]){
            if(d[v]>n){
                d[v]=d[u]+1;
                q[++tl]=v;
            }
        }
    }
    int ans=*max_element(d+1,d+n+1);
    assert(ans<=n);
    return ans;
}
signed main(){
    FRE("hub");
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        fr(i,1,n)eg[i].clear();
        fr(i,1,n-1){
            int u,v;
            cin>>u>>v;
            eg[u].eb(v);
            eg[v].eb(u);
        }
        int ans=n+1;
        for(z=0;z<=(1<<n)-1;z++)if(__builtin_popcount(z)==k){
            ci=0;
            fr(i,1,n)c[i]=0;
            fr(i,1,n){
                if((z>>i-1&1)&&!c[i]){
                    ci++;
                    color(i);
                }
            }
            if(ci>2)continue;
            int an=bfs();
            // fr(i,1,n)pt("%d",z>>i-1&1);pt("\n");
            // Z(an);
            ans=min(ans,an);
        }
        pt("%d\n",ans);
    }
    return 0;
}