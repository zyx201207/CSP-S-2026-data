#include<bits/stdc++.h>
#define fi first
#define se second
// #define W(x) cerr<<#x<<':'<<x<<'\n'
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
using namespace std;
using ll=long long;
using db=long double;
using ull=unsigned long long;
const int N = 1e6+10;
const int M = 1e5+10;
const int MOD = 1e9+7;
namespace IO{
    template<typename T> inline void rd(T &x){
        x=0;
        bool f = 0;
        char c = gc();
        for(;!isdigit(c);c=gc())if(c=='-')f=1;
        for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
        if(f)x=-x;
    }
    template<typename T> inline void wt(const T &x){
        if(x<0){
            pc('-');
            wt(-x);
            return;
        }
        if(x>9){
            wt(x/10);
        }
        pc(x%10+'0');
    }
}using namespace IO;
int subtask,T,n,k,Ans;
vector<int> g[N];
bitset<N> vis;
bitset<N> vis1;

void dfs2(int u){
    vis1[u] = 1;
    for(int v : g[u]){
        if(vis[v]&&!vis1[v])dfs2(v);
    }
}
int dfs3(int u,int fath){
    if(vis[u])return 0;
    int now = INT_MAX;
    for(int v : g[u]){
        if(v==fath)continue;
        now = min(now,dfs3(v,u));
    }
    return now + 1;
}

void dfs(int step,int sum){
    if(step==n+1&&sum==k){
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            vis1[i] = 0;
        }
        for(int i = 1;i<=n;i++){
            if(vis[i]&&!vis1[i]){
                cnt++;
                dfs2(i);
            }
        }
        if(cnt!=2)return;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans = max(ans,dfs3(i,0));
        }
        Ans = min(Ans,ans);
        return;
    }
    if(step==n+1)return;
    vis[step] = 1;
    if(sum<k)dfs(step+1,sum+1);
    vis[step] = 0;
    dfs(step+1,sum);
}
void solve1(){
    while(T--){
        rd(n),rd(k);
        for(int i = 1;i<=n;i++){
            g[i].clear();
            vis[i] = 0;
        }
        for(int i = 1;i<n;i++){
            int u,v;
            rd(u),rd(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        Ans = INT_MAX;
        dfs(1,0);
        wt(Ans),pc('\n');
    }
}
void solve2(){
    while(T--){
        rd(n),rd(k);
        for(int i = 1;i<n;i++){
            int u,v;
            rd(u),rd(v);
        }
        n = n/2+1;
        int sidea = k/2;
        int sideb = n-k/2;
        int posl = n/3,posr = n-n/3+1;
        int posll = posl-sidea/2+1;
        int poslr = posl+(sidea-sidea/2)-1;
        int posrl = posr-sideb/2+1;
        int posrr = posr+(sideb-sideb/2)-1;
        int ans = max(posll-1,max(posrl-poslr,n-posrr));
        cout << ans << '\n';
    }
    return;
}
void solve3(){
    while(T--){
        rd(n),rd(k);
        for(int i = 1;i<=n;i++){
            g[i].clear();
            vis[i] = 0;
        }
        for(int i = 1;i<n;i++){
            int u,v;
            rd(u),rd(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int Ans = INT_MAX;
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                vis[i] = vis[j] = 1;
                int ans = 0;
                for(int u = 1;u<=n;u++){
                    ans = max(ans,dfs3(u,0));
                }
                Ans = min(Ans,ans);
            }
        }
        wt(Ans);
        pc('\n');
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    rd(subtask),rd(T);
    if(subtask==13||subtask==14){
        solve2();
    }else if(subtask==7){
        solve3();
    }
    else{
        solve1();
    }

    return 0;
}
/*
compile:
g++ -o D D.cpp -O2 -static -std=c++14


0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/