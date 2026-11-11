#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ffor(i,j,k) for(ll i=(j);i<=(k);i++)
#define rfor(i,j,k) for(ll i=(k);i>=(j);i--)
#define vec vector
#define pq priority_queue
#define sta stack
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define pii pair<ll,ll>
#define debug(x) cout<<"DEBUG:"<<x<<endl;
#define __ " "
#define endl '\n'
vec<pii>G1[500005*21];
vec<pii>G2[500005];
vec<int>line[505];
int cnt[500005];
struct Node{
    int id,chk;
    ll val;
}nodes[5000005*22];
struct chks{
    int x;
    ll val;
    bool operator<(const chks c)const{
        return val < c.val;
    }
};
int idx(int g,int k){
    return (g-1)*21+k;
}
const int N = 500005*20;
ll ans[505][505];
#define gc getchar_unlocked
void read(ll &x){
    x=0;int f =1;
    char c = gc();
    while(!isdigit(c)){
        if(c == '-'){
            f = 1;
        }c = gc();
    }
    while(isdigit(c)){
        x = x*10+c-'0';
        c=gc();
    }
    x*=f;
}
ll w[500005];
void solve(){
    memset(ans,0x3f,sizeof ans);
    ll c,n,m,d,qq;
    read(c);read(n);read(m);read(d);read(qq);
    ffor(i,1,m)read(w[i]),cnt[i] = 1;
    ffor(i,1,n){
        ll l;read(l);
        ll lx = -1;
        ffor(j,1,l){
            ll x,t;
            read(x);read(t);
            G1[idx(x,1)].pb({idx(x,++cnt[x]),t});
            G1[idx(x,cnt[x])].pb({idx(x,1),t});
            nodes[idx(x,cnt[x])] = {x,i,t};
        }
    }
    ffor(i,1,m){//2e8
        ffor(j,0,(int)G1[idx(i,1)].size()-1){
            ffor(k,j+1,(int)G1[idx(i,1)].size()-1){
                ans[nodes[G1[idx(i,1)][j].fi].chk][nodes[G1[idx(i,1)][k].fi].chk] = min(
                    ans[nodes[G1[idx(i,1)][j].fi].chk][nodes[G1[idx(i,1)][k].fi].chk],
                    G1[idx(i,1)][j].se + G1[idx(i,1)][k].se
                );
                ans[nodes[G1[idx(i,1)][k].fi].chk][nodes[G1[idx(i,1)][j].fi].chk] = min(
                    ans[nodes[G1[idx(i,1)][k].fi].chk][nodes[G1[idx(i,1)][j].fi].chk],
                    G1[idx(i,1)][j].se + G1[idx(i,1)][k].se
                );
            }
        }
    }
    ffor(i,1,n)ans[i][i] = 0;
    ffor(i,1,n){
        ffor(j,1,n){
            ffor(k,1,n){
                ans[i][j] = min(ans[i][j],ans[i][k]+ans[k][j]);
            }
        }
    }

    while(qq--){
        ll a,b;
        read(a);read(b);
        ll anss = 1e18;
        ffor(i,2,21){
            ffor(j,2,21){
                if(nodes[idx(a,i)].chk != 0 && nodes[idx(b,j)].chk != 0){
                    anss = min(anss,ans[nodes[idx(a,i)].chk][nodes[idx(b,j)].chk]
                        +nodes[idx(a,i)].val+nodes[idx(b,j)].val
                    );
                }else break;
            }
        }
        cout<<anss+w[a]+w[b]<<endl;
    }

}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
