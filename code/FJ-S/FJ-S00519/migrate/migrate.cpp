#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 5;
int c, T, n, dis[N], nxt[N];
ll a[N], ans, d;
vector<int>S[N];
void init(){
    ans = 0;
    for(int i = 1;i <= n;++i)dis[i] = a[i] = nxt[i] = 0;
}
queue<int>q;
void work(int s){
    int l = s - 1, nn = 1;
    q.push(s), dis[s] = 1;
    while(!q.empty()){
        int x = q.front();q.pop();
        S[dis[x]].push_back(x), nn = dis[x];
        for(;l;--l){
            if(a[x] - a[l] > d)break;
            dis[l] = dis[x] + 1, q.push(l);
        }
        nxt[x] = l + 1;
    }
    int len = 0, nl = 0;
    for(int i = 1;i <= nn;++i)sort(S[i].begin(), S[i].end());
    //for(int i = l + 1;i <= s;++i)cerr <<i << ' ' << dis[i] <<'\n';
    for(int i = nn;i > 1;--i){
        if(S[i].size() == 1){++nl, ans += 1ll * len * S[i - 1].size();continue;}
        for(int x : S[i]){
            if(dis[nxt[x]] != i)continue;
            if(S[i + 1].size() == 1){
                if(nxt[x] + 1 != x)ans += (len = nl * (nxt[nxt[x] + 2] - nxt[nxt[x] + 1]));
                else{len = 0;}
            }else{
                if(nxt[x] + 1 != x)ans += (len = nxt[nxt[x] + 2] - nxt[nxt[x] + 1]);
                else{len = 0;}
            }
        }
        for(int x : S[i - 1]){
            if(S[i + 1].size() == 1){
                if(dis[nxt[x]] == i && nxt[x] + 1 != x)ans += (len = nl * (nxt[nxt[x] + 2] - nxt[nxt[x] + 1]));
                else{len = 0;}
            }else{
                //cerr << nxt[x] + 2<<nxt[x] + 1;
                if(dis[nxt[x]] == i && nxt[x] + 1 != x)ans += (len = nxt[nxt[x] + 2] - nxt[nxt[x] + 1]);
                else{len = 0;}
            }
        }
        nl = S[i].size();
    }for(int i = 1;i <= nn;++i)S[i].clear();
    cerr << '\n';
}
void solve(){
    scanf("%d%lld", &n, &d), init();
    for(int i = 1;i <= n;++i)scanf("%lld", &a[i]);
    for(int i = n;i;--i)if(!dis[i])work(i);
    printf("%lld\n", ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d", &c, &T);
    while(T--)solve();
    return 0;
}