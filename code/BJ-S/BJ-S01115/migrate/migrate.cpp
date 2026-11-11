#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
long long dp[5005];
long long lst[5005];long long n,d;
long long cnt[5005];
long long q[5005],l=1,r=0;

bool do_dp(int u,int v){
    //cout  << u << " " << v <<"\n";
    memset(dp,0x3f,sizeof dp);
    memset(cnt,0,sizeof cnt);
    memset(lst,0,sizeof lst);
    dp[u] = 0;l=1,r=0;
    q[++r] = u;

    for (int i = u+1; i <= v; i++){
        while (a[i]-a[q[l]] > d && l <= r) l++;
        if (dp[q[l]] == dp[q[l+1]] && dp[q[l+2]] == dp[q[l+1]] && r >= l+2) cnt[i] += 3;
        else if (dp[q[l]] == dp[q[l+1]] && r >= l+1) cnt[i] += 2/*,cout <<a[i]-a[q[l]] << " "<< q[l+1] << "|||\n"*/;
        else cnt[i] ++;
        if (l <= r){
            lst[i] = q[l];
            dp[i] = dp[q[l]]+1;
            while (l <= r && dp[q[r]] > dp[i]) r--;
            q[++r] = i;
        }


    }
    long long num = 1;
    for (int i = v; i != 0; i = lst[i]){
        num *= max(cnt[i],1LL);
        //cout << i << " " << cnt[i] <<" " << u << " " << v <<"\n";
    }
    return (num==2);
}
void _init_(){
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long js = a[2]-a[1],bs = d/js;
    if (bs <= 1){cout << "0\n";return ;}
    long long cnt = 0;
    for (int u = 1; u <= n; u++){
        int r =u+2*bs-1;
        if (r > n) continue;
        //if (bs == 1 && r-l+1 > 0) cout << u <<"| ";
        cnt ++;
    }
    cout << cnt << "\n";
}

void _init2_(){
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long cnt = 0;
    for (int u = 1; u <= n; u++){
        for (int v = u+1; v <= n; v++)
            cnt += do_dp(u,v);
    }
    cout << cnt << "\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,q; cin >> c >>q;
    if (c == 11 || c == 12){
        while (q--) _init_();
        return 0;
    }
    while (q--) _init2_();
    return 0;
}
