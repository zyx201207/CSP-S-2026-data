#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10, maxlog = 22, maxn__ = 5009;
int c, t, n;
ll d, x[maxn];
int str[maxn][maxlog], stl[maxn][maxlog];
int dis[maxn__][maxn__];
ll solve2(int siz, int _mr[], int _ml[]){//联通部分
    ll ans = 0;
    int cnt = 0;
    for(int i = 1; i < siz; i = _mr[i]) cnt++;
    if(cnt <= 1) return 0;
    for(int i = 1; i <= siz; i++){
        str[i][0] = _mr[i];
    }
    for(int i = 1; i <= siz; i++){
        for(int j = 1; j <= siz; j++){
            dis[i][j] = maxn;
        }
    }
    for(int i = 1; i <= siz; i++){
        dis[i][i] = 0;
        for(int k = 1, rea = i; k <= cnt; k++){
            for(int j = rea + 1; j <= _mr[rea]; j++) dis[j][i] = dis[i][j] = k;
            rea = _mr[rea];
            if(rea == siz) break;
        }
    }
    for(int i = 1; i <= siz; i++){
        for(int k = _mr[i] + 1; k <= siz; k++){
            int wcnt = 0;
            for(int j = i + 1; j <= _mr[i]; j++){
                if(dis[j][k] == (dis[i][k] - 1)) wcnt++;
            }
            if(wcnt == 2) ans++;
        }
    }
    return ans;
    /*
    int mk = 0;
    for(int k = 1; (1 << k) <= cnt; k++){
        mk = k;
        for(int i = 1; i <= siz; i++){
            str[i][k] = str[str[i][k - 1]][k - 1];
        }
    }
    for(int i = 1; i <= siz; i++){
        stl[i][0] = _ml[i];
    }
    for(int k = 1; (1 << k) <= cnt; k++){
        for(int i = 1; i <= siz; i++){
            stl[i][k] = stl[stl[i][k - 1]][k - 1];
        }
    }
    */
    return -1;
}
/*
ll solve2(int siz, int _mr[], int _ml[]){//联通部分
    int cnt = 0;
    for(int i = 1; i < siz; i = _mr[i]) cnt++;
    if(cnt <= 1) return 0;
    //cnt == 2
    int ans = 0;
    for(int i = 1; i <= siz; i++){
        for(int x = lower_bound(_ml + 1, _ml + siz + 1, _mr[i] - 1) - _ml;
            (_mr[i] - _ml[x]) == 1; x++) ans++;
    }
    return ans;
}
*/
int mr[maxn], ml[maxn];
ll solve1(){
    scanf("%d %lld", &n, &d);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &x[i]);
    }
    {
        int p = 1;
        for(int i = 1; i <= n; i++){
            while((p < i) && (x[i] - x[p] > d)){
                mr[p++] = i - 1;
            }
        }
        for(; p <= n; p++){
            mr[p] = n;
        }
    }
    {
        int p = n;
        for(int i = n; i >= 1; i--){
            while((p > i) && (x[p] - x[i] > d)){
                ml[p--] = i + 1;
            }
        }
        for(; p >= 1; p--){
            ml[p] = 1;
        }
    }

    ll ans = 0;
    for(int i = 1, last = 0; i <= n; i++){
        if(mr[i] > i) continue;
        ans += solve2(i - last, mr + last, ml + last);
        last = i;
    }
    return ans;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--){
        printf("%lld\n", solve1());
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
