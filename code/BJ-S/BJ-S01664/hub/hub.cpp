#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+6;
int n,k,ans;
int len,p;
int dep[N];
int siz[N],is[N];
vector<int>e[N];
void dfs(int x,int fa){
    siz[x] = is[x];
    for(auto i:e[x]){
        if(i != fa){
            dfs(i,x);
            siz[x] += siz[i]-(is[i]&&is[x]);
        }
    }
}
void dfs1(int x,int fa){
    dep[x] = dep[fa]+1;
    if(dep[x] > len){
        len = dep[x];
        p = x;
    }
    for(auto i:e[x]){
        if(i != fa){
            dfs1(i,x);
        }
    }
}
vector<int>nw;
int zhi[N],fll;
void dfs2(int x,int fa){
    dep[x] = dep[fa]+1;
    nw.push_back(x);
    if(dep[x] == len && !fll){
        for(int i = 1;i <= len;i++){
            zhi[i] = nw[i-1];
            is[zhi[i]] = 1;
        }
        fll = 1;
    }
    for(auto i:e[x]){
        if(i != fa){
            dfs2(i,x);
        }
    }
    nw.pop_back();
}
int ma[N];
void dfs3(int x,int fa,int &mx){
    if(fa)dep[x] = dep[fa]+1;
    else dep[x] = 0;
    mx = max(mx,dep[x]);
    for(auto i:e[x]){
        if(i != fa && !is[i]){
            dfs3(i,x,mx);
        }
    }
}
int mh[N],mq[N];
void sol(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        e[i].clear();
        ma[i] = mh[i] = mq[i] = is[i] = 0;
    }
    for(int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(n <= 10){
        ans = n;
        for(int i = 0;i < (1<<n);i++){
            if(__builtin_popcount(i) != k){
                continue;
            }
            for(int j = 1;j <= n;j++){
                is[j] = ((i>>(j-1))&1);
            }
            dfs(1,0);
            if(siz[1] > 2) continue;
            int an = 0;
            for(int j = 1;j <= n;j++){
                for(int k = 1;k <= n;k++){
                    if(is[k]) continue;
                    an = j;
                    for(auto x:e[k]){
                        if(is[x] == j){
                            is[k] = j+1;
                            break;
                        }
                    }
                }
            }
            ans = min(ans,an);
        }
        cout << ans << endl;
        return;
    }
    len = p = 0;
    dfs1(1,0);
    len = 0;
    dfs1(p,0);
    fll = 0,nw.clear();
    dfs2(p,0);
    for(int i = 1;i <= len;i++){
        ma[i] = 0;
        dfs3(zhi[i],0,ma[i]);
        mh[i] = mq[i] = 0;
    }
    ans = len/2;
    for(int i = len;i >= 1;i--){
        mh[i] = max(mh[i+1]+1,ma[i]);
        if(i == len/2 || i == len){
            mh[i] = ma[i];
        }
    }
    for(int i = 1;i <= len;i++){
        mq[i] = max(mq[i-1]+1,ma[i]);
        if(i == len/2+1 || i == 1){
            mq[i] = ma[i];
        }
    }
    for(int i = 1,j = len;i < j;i++,j--){
        ans = min(ans,max(max(mq[i],mh[i]),max(mq[j],mh[j])));
    }
    cout << ans << endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int __,_;
    cin >> __ >> _;
    while(_--){
        sol();
    }
}
