#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
int m, n, c, T;
int h[N], ver[2 * N], nxt[2 * N], tot;
void add(int x, int y){
    ver[++tot] = y;
    nxt[tot] = h[x];
    h[x] = tot;
}
int rtl, rtr, r;
void dfs1(int x, int l, int fa){
    if(l > r){
        r = l;
        rtl = x;
    }
    for(int i = h[x]; i; i = nxt[i]){
        int y = ver[i];
        if(y == fa)continue;
        dfs1(y, l + 1, x);
    }
}
struct node{
    int x, md;
}d[N];
bool dfs2(int x, int p, int fa){
    d[p].x = x;
    if(x == rtr)return 1;
    for(int i = h[x]; i; i = nxt[i]){
        int y = ver[i];
        if(y == fa)continue;
        if(dfs2(y, p + 1, x))return 1;
    }
    return 0;
}
int de[N];
void dfs3(int x, int rt, int dep, int fa){
    d[rt].md = max(d[rt].md, dep);
    de[x] = dep;
    for(int i = h[x]; i; i = nxt[i]){
        int y = ver[i];
        if(y == fa)continue;
        dfs3(y, rt, dep + 1, x);
        de[x] = max(de[x], de[y]);
    }
}
int cnt;
void dfs4(int x, int dep, int fa, int p){
    cnt++;
    for(int i = h[x]; i; i = nxt[i]){
        int y = ver[i];
        if(de[y] - dep <= p || y == fa)continue;
        dfs4(y, dep + 1, x, p);
    }
}
bool check(int p){
    int lh = p + 1, rh = r - p; cnt = 2;
    if(rh <= lh)return 1;
    for(int i = lh; i <= rh; i++){
        if(d[i].md + min(i - lh, rh - i) > p){
            if(i - lh < rh - i){
                if(d[i].md <= p){
                    cnt += i - lh - p + d[i].md;
                    lh = i - p + d[i].md;
                }
                else{
                    cnt += i - lh;
                    lh = i;
                    for(int j = h[d[i].x]; j; j = nxt[j]){
                        int y = ver[j];
                        if(de[y] <= p)continue;
                        dfs4(y, 1, d[i].x, p);
                    }
                }
                if(cnt > m)return 0;
            }
            else{
                if(d[i].md <= p){
                    cnt += rh - i - p + d[i].md;
                    rh = i + p - d[i].md;
                }
                else{
                    cnt += rh - i;
                    rh = i;
                    for(int j = h[d[i].x]; j; j = nxt[j]){
                        int y = ver[j];
                        if(de[y] <= p)continue;
                        dfs4(y, 1, d[i].x, p);
                    }
                }
                if(cnt > m)return 0;
            }
        }
    }
    return 1;
}
int ef(int l, int r){
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    return l;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> T;
    int x, y;
    while(T--){
        cin >> n >> m;
        memset(h, 0, sizeof h);
        memset(ver, 0, sizeof ver);
        memset(nxt, 0, sizeof nxt);
        tot = 0;
        for(int i = 1; i <= n - 1; i++){
            scanf("%d %d", &x, &y);
            add(x, y);
            add(y, x);
        }
        rtr = rtl = r = 0;
        dfs1(1, 1, 0);
        rtr = rtl;r = 0;
        dfs1(rtr, 1, 0);
        memset(d, 0, sizeof d);
        dfs2(rtl, 1, 0);
        memset(de, 0, sizeof de);
        for(int i = 1; i <= r; i++)
            for(int j = h[d[i].x]; j; j = nxt[j]){
                if(ver[j] == d[i - 1].x || ver[j] == d[i + 1].x)continue;
                dfs3(ver[j], i, 1, d[i].x);
            }
        if(m == n)puts("0");
        else printf("%d\n", ef(1, r));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
