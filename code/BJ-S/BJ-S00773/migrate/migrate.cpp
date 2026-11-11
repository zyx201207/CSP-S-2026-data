#include <bits/stdc++.h>
#define int long long

using namespace std;

int c, t;
int n, d;
int xi[2000010];
int now, minn, minp;

void chk(int fr, int to){
    if (now > minn) return;
    if (xi[to] - xi[fr] <= d){
        //cout << 'b';
        now++;
        if (minn > now){
            minn = now;
            minp = 1;
        } else if (minn == now){
            minp++;
        }
        now--;
        return;
    }
    int i;
    now++;
    for (i = fr + 1; i < to && (xi[i] - xi[fr]) <= d; i++){
        chk(i, to);
    }
    now--;
    /*
    if (xi[to] - xi[i] <= d && i != to){
        cout << 'a';
        now++;
        if (minn > now){
            minn = now;
            minp = 1;
        } else if (minn == now){
            minp++;
        }
        now--;
        return;
    }
    now--;
    */
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> d;
        for (int i = 1; i <= n; i++){
            cin >> xi[i];
        }
        int ans = 0;
        for (int i = 1; i < n; i++){
            for (int j = i + 3; j <= n; j++){
                now = 0;
                minn = LLONG_MAX;
                minp = 0;

                int ttt = 0, noww = i;
                bool flag = 1;
                for (int k = i + 1; k <= j; k++){
                    if (xi[k] - xi[k - 1] > d){
                        flag = 0;
                        break;
                    }
                    if (xi[k] - xi[noww] > d){
                        ttt++;
                        noww = k - 1;
                    }
                }
                ttt++;
                minn = ttt;
                if(!flag)continue;
                chk(i, j);
                if (minp == 2)ans++;
                //cout << i << " " << j << endl;
                //cout << minn << " " << minp << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
