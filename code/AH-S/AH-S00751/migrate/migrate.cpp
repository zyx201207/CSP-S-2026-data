#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n, d;
int c, T;
const int N = 2e+6+5;
int x[N]; int  f[N];
bool check(int l, int r){
    int fir = l, cnt = 0;
    while(fir+2 <= r){
        if(x[fir]+d < x[fir+1]) return false;
        while(fir+2 < r && x[fir]+d >= x[fir+1] && x[fir]+d < x[fir+2]) fir++;
        if(fir+2 >= r) return false;

        int sec = fir;
        //cout <<"HI" << endl;
        while(sec+3 < r || (x[sec]+d >= x[sec+2] && x[sec]+d < x[sec+3])) sec++;
        cnt++;
        if(sec == fir || sec > fir+1) return false;
        fir = sec+1;
    }
    return cnt == 1;
}
void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    int ans = 0;
    //cout << "ogineonrg" << endl;
    for(int l = 1; l <= n; l++)
        for(int r = l+3; r <= n; r++)
            if(check(l, r)) {
                ans++;
                //cout << l << ' ' << r << '\n';
            }
    cout << ans << '\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
/**
 d = 3
 x 0 3 6 7 8 9 10 11 14 17
 f 1 1 - - - - 1  1  -  -


**/
