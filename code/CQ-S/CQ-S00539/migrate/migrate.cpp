#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
bool ST; namespace furina{
    const int N = 2e6, inf = 0x7fffffff >> 1;

    int n;
    ll d;
    ll x[N + 10];

    int nxt[N + 10], lst[N + 10];
    
    ll f[N + 10][2];
    int t[N + 10];

    inline void solve(){
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> x[i];
        
        for(int i = 1, r = 1; i <= n; i++){
            while(r < n && x[i] + d >= x[r + 1])
                r++;
            nxt[i] = r;
        }
        for(int i = n, l = n; i >= 1; i--){
            while(l > 1 && x[i] - d <= x[l - 1])
                l--;
            lst[i] = l;
        }
        
        for(int i = 1; i <= n; i++){
            int x = nxt[i], y = nxt[x];
            //非开头
            if(x > i && y > x && lst[y] == x - 1 && lst[x - 1] == i)
                f[y][1] += f[i][0];
            if(x > i && lst[x] == i)
                f[x][0] += f[i][0], f[x][1] += f[i][1];

            //开头
            if(x > i && y > x && lst[y] == x - 1)
                f[y][1]++;
            if(x > i)
                f[x][0]++;
        }

        //情况2
        ll ans = 0;
        for(int i = 1; i <= n; i++)
            t[i] = 0;
        for(int i = n; i >= 1; i--)
            ans += f[i][1] * t[i], t[lst[i]]++;
        
        //情况1
        //非开头
        for(int i = 1; i <= n; i++)
            t[i] = 0;
        for(int i = n; i >= 1; i--){
            if(nxt[lst[i]] == i && lst[i] < i)
                if(lst[i] == lst[i - 1] && lst[i - 1] < i - 1)
                    ans += f[lst[i]][0] * t[i - 1];
            t[lst[i]]++;
        }

        //开头
        for(int i = 1; i <= n; i++)
            t[i] = 0;
        for(int i = n, cur = n; i >= 1; i--){
            if(nxt[i] > i){
                while(cur > nxt[i])
                    t[lst[cur--]]++;
                ans += t[nxt[i] - 1];
            }
        }

        cout << ans << '\n';
    }

    int main(){
        int c, T;
        cin >> c >> T;
        while(T--){
            solve();
            //clear
            for(int i = 1; i <= n; i++)
                f[i][0] = f[i][1] = 0;
        }
        return 0;
    }
} bool ED;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    furina::main();
    cerr << (1000. * clock() / CLOCKS_PER_SEC) << "ms" << '\n';
    cerr << (abs(&ST - &ED) >> 20) << "mb" << '\n';
    return 0;
}
/*
g++ -o migrate migrate.cpp -std=c++14 -Wall -O2 -lm -Wl,--stack=2000000000 & .\migrate

g++ -o migrate migrate.cpp -std=c++14 -Wall -O2 -lm -Wl,--stack=2000000000
migrate < migrate1.in > migrate.out & fc migrate.out migrate1.ans
migrate < migrate2.in > migrate.out & fc migrate.out migrate2.ans
migrate < migrate3.in > migrate.out & fc migrate.out migrate3.ans
migrate < migrate4.in > migrate.out & fc migrate.out migrate4.ans
migrate < migrate5.in > migrate.out & fc migrate.out migrate5.ans
migrate < migrate6.in > migrate.out & fc migrate.out migrate6.ans
*/