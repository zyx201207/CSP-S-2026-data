//get nxt & lst -> find one way islands -> find foundational 2 way islands
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int xn = 2000006;
int c, t, n, nxt[xn], lst[xn]; ll d, owi[xn][2], fti[xn][2], x[xn], ans;
struct ild{
    ll ps; int id;
};
struct Rg{
    int l, r;
    inline bool in(void){ return l > 0 && r > 0; }
}rls[xn], rnx[xn];

int main(){
freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout); 
    scanf("%d %d", &c, &t);
    while(t--){
    scanf("\n%d %lld\n", &n, &d); ans = 0;
    for(int i = 1; i <= n; ++i) scanf("%lld", x + i);
    deque<ild> q;
    for(int i = 1; i <= n; ++i){
        while(!q.empty() && q.front().ps < x[i] - d){
            nxt[q.front().id] = q.back().id;
            if(!rnx[q.back().id].l){ rnx[q.back().id].l = q.front().id; }
            rnx[q.back().id].r = q.front().id;
            q.pop_front();
        }
        q.push_back({x[i], i});
    }
    while(!q.empty()){
        nxt[q.front().id] = n;
        if(!rnx[n].l){ rnx[n].l = q.front().id; }
        q.pop_front();
    }
    rnx[n].r = n;
    for(int i = n; 0 < i; --i){
        while(!q.empty() && q.front().ps > x[i] + d){
            lst[q.front().id] = q.back().id;
            if(!rls[q.back().id].l){ rls[q.back().id].l = q.front().id; }
            rls[q.back().id].r = q.front().id;
            q.pop_front();
        }
       q.push_back({x[i], i});
    }
    while(!q.empty()){
        lst[q.front().id] = 1; if(!rls[1].l) rls[1].l = q.front().id;
        q.pop_front();
    }
    rls[1].r = 1;
    owi[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        if(nxt[i] != i && lst[i] != i && nxt[lst[i]] == i) owi[i][0] = owi[lst[i] - 1][0] + 1;
        else owi[i][0] = 1;
      //  printf("owi:%d %lld\n", i, owi[i][0]);
        int m1 = nxt[i], r = nxt[m1], m2 = m1 - 1, l = lst[m2];
        if(m1 == r) continue;
        if(l <= i){
            int ll = rls[m2].l, rr = rls[m2].r;
            if(ll > r) continue; r = min(r, rr);
            ans += owi[i][0] * (r - ll + 1); //printf("fond:%d %d %d\n", i, r, ans);
        }
    }
    owi[n + 1][1] = 1;

    for(int i = n; 0 < i; --i){
        if(nxt[i] != i && lst[nxt[i]] == i) owi[i][1] = owi[nxt[i] + 1][1] + 1;
        else owi[i][1] = 1;
      //  printf("owi%d %lld\n", i, owi[i][1]);
        int m1 = lst[i], r = lst[m1], m2 = m1 + 1, l = nxt[m2];
        if(m1 == r) continue;
        if(l >= i){
            int ll = rnx[m2].l, rr = rnx[m2].r;
            if(ll < r) continue; r = max(r, rr);
            ans += owi[i][0] * (ll - r + 1) - 1; //printf("fond:%d %d %d %d\n", i, ll, r, ans);
        }
    }
    printf("%lld\n", ans);
    }
    return 0;
}
