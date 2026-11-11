#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e6 + 10;

int n;
ll d;
int l[N], r[N], bl[N], br[N];
ll x[N], pre[N];

void BruteForce(){
    ll ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = i - 1; j <= n; j ++) pre[j] = 0;
        pre[i] = 1;
        int lst = i;
        for(int j = i + 1; j <= n; j ++){
            if(bl[j] > lst) lst = j - 1;
            ll res = pre[lst] - pre[max(bl[j], i) - 1];
            if(res == 2){
                ans ++;
            }
            pre[j] = pre[j - 1] + res;
        }
    }
    cout <<ans<<"\n";
}

ll cnt[N], dep[N], le[N];
ll ans = 0;
void solve(int st){
    // cout <<st<<"f\n";
    pre[st - 1] = 0; pre[st] = 1;
    cnt[st] = 1; dep[st] = 0;
    int lst = st, ed = n, fir = st;
    le[1] = st + 1;
    for(int j = st + 1; j <= n; j ++){
        if(bl[j] > lst){
            if(bl[j] == j){
                ed = j - 1;
                break;
            }
            if(fir == st) fir = j - 1;
            lst = j - 1;
            le[dep[lst] + 1] = j;
        }
        dep[j] = dep[lst] + 1;
        ll res = pre[lst] - pre[max(bl[j], st) - 1];
        pre[j] = pre[j - 1] + res;
        cnt[j] = res;
    }
    if(dep[ed] >= 2){
        for(int i = le[dep[2]]; i <= ed; i ++){
            int pos = le[dep[i]] + 2 - cnt[i];
            if(cnt[i] > 2 || pos > i) continue;
            int j = st, o = 0;
            while(dep[j + 1] == 1){
                o = 0;
                int cur = j;
                while(dep[cur] < dep[i]) cur = r[cur] + 1, o ++;
                //cout <<o;
                if(cur == pos && o == dep[i] - 1){
                    ans ++;
                    // cout <<i<<" "<<j<<"\n";
                }
                j ++;
            }
        }
    }
    if(fir + 1 < n) solve(fir + 1);
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c, T;
    cin >>c>>T;
    while(T --){
        cin >>n>>d;
        ans = 0;
        for(int i = 1; i <= n; i ++) cnt[i] = le[i] = pre[i] = 0;
        for(int i = 1; i <= n; i ++) cin >>x[i];
        for(int i = 1; i <= n; i ++){
            l[i] = i + 1;
            r[i] = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
            br[i] = i - 1;
            bl[i] = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
        }
        if(c <= 10) BruteForce();
        else{
            solve(1);
            cout <<ans<<"\n";
        }
    }
    return 0;
}
/*
0 1
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/