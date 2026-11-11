#include<bits/stdc++.h>
using namespace std;
long long MAXN = 2000000000000000000;
struct klp{
    int kd;
    long long bp;
    long long val;
};
struct lp{
    int aim;
    long long val;
};
struct xd{
    int aim;
    int kd;
    long long l, r;
};
struct sp{
    int aim;
    int kd;
    long long bp;
    long long val;
};
vector<klp>vp[500010];
long long w[500010];
vector<xd>vt[500010];
priority_queue<sp>q;
int f[500010];
long long dp[500010];
bool operator< (sp x, sp y){
    return x.val > y.val;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, ql;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &ql);
    for(int i = 1; i <= m; i++){
        scanf("%lld", &w[i]);
    }
    for(int i = 1; i <= n; i++){
        int cnt;
        scanf("%d", &cnt);
        lp t;
        cin >> t.aim >> t.val;
        klp et;
        et.kd = i;
        et.val = t.val;
        et.bp = t.val;
        vp[t.aim].push_back(et);
        for(int j = 2; j <= cnt; j++){
            int x;
            long long cal;
            scanf("%d%lld", &x, &cal);
            et.val = cal;
            vp[c].push_back(et);
            xd re;
            re.aim = c;
            re.kd = i;
            re.l = t.val;
            re.r = cal;
            vt[t.aim].push_back(re);
            re.aim = t.aim;
            vt[c].push_back(re);
            t.aim = c;
            t.val = cal;
        }
    }
    while(ql--){
        int x, y;
        cin >> x >> y;
        if(x == y){
            cout << 0;
            continue;
        }
        long long ans = MAXN;
        for(int i = 0; i < vp[x].size(); i++){
            sp e;
            e.aim = x;
            e.kd = vp[x][i].kd;
            e.val = vp[x][i].val;
            e.bp = e.val;
            memset(f, 0, sizeof(f));
            for(int i = 1; i <= m; i++){
                dp[i] = MAXN;
            }
            dp[x] = w[x] + e.val;
            q.push(e);
            while(!q.empty()){
                int xx = q.top().aim;
                int yy = q.top().kd;
                long long zz = q.top().bp;
                q.pop();
                if(f[xx] == 1){
                    continue;
                }
                f[xx] = 1;
                for(int i = 0; i < vt[xx].size(); i++){
                    if(yy == vt[xx][i].kd){
                        if(dp[vt[xx][i].aim] > dp[xx]){
                            dp[vt[xx][i].aim] = dp[xx];
                            sp re;
                            re.aim = vt[xx][i].aim;
                            re.kd = yy;
                            re.bp = vt[xx][i].r;
                            re.val = dp[vt[xx][i].aim];
                            q.push(re);
                        }
                    }
                    else{
                        if(dp[vt[xx][i].aim] > dp[xx] + zz + vt[xx][i].l){
                            dp[vt[xx][i].aim] = dp[xx] + zz + vt[xx][i].l;
                            sp re;
                            re.aim = vt[xx][i].aim;
                            re.kd = vt[xx][i].kd;
                            re.bp  = vt[xx][i].r;
                            re.val = dp[vt[xx][i].aim];
                            q.push(re);
                        }
                    }
                }
            }
            ans = min(ans, dp[y] + w[y]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
