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
int c;
void solve(){
    int n,k;
    cin>>n>>k;
    vec<int>G[n+1];
    ffor(i,1,n-1){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    ll ans = 1e18;
    ffor(i,0,(1LL<<(n+1))+1){
        int x=i;
        int cnt=1;
        while(x){
            if(x&1)cnt++;
            x>>=1;
        }
        if(cnt == k){
            queue<int>q;
            q.push(1);
            vec<ll>col(n+1,0),vis(n+1,0),dis(n+1,0),fa(n+1,0);
            dis[1] = 0;
            cnt = 0;
            bool flag = 0;
            while(!q.empty()){
                int x = q.front();q.pop();
                vis[x] = 1;
                if((1<<x)&i == 1 && col[x] == 0){
                    col[x] = ++cnt;
                    if(cnt>2){flag = 1;break;}
                }
                for(auto u:G[x]){
                    if(vis[u])continue;
                    if((1<<u)&i == 1 && col[u] == 0){
                        col[u] = cnt;
                    }
                    q.push(u);
                    dis[u] = dis[x]+1;
                    fa[u] = x;
                }
            }if(flag)break;
            ll anss = 1e18;
            ffor(j,1,n){
                ll chk = 0;
                if((1<<j)&i == 1){
                    continue;
                }
                ffor(c,1,n){
                    if((1<<c)&i == 1){
                        int ls = c,rs = j;
                        if(dis[ls]<dis[rs])swap(rs,ls);
                        while(dis[ls]>dis[rs]){
                            ls = fa[ls];
                        }
                        while(ls!=rs){
                            ls = fa[ls],rs = fa[rs];
                        }
                        if(ls == 1){
                            chk = max(chk,dis[c]+dis[j]);
                        }else chk = max(chk,abs(dis[c]-dis[j]));
                    }
                }
                ans = min(ans,chk);
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
