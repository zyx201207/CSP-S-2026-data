#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<assert.h>
#include<ctime>
#include<vector>
#define int long long
typedef long long LL;
#define PII pair<int, int>
using namespace std;
bool st_m;
namespace Read{
    inline int read(){
        int f = 0, d = 1; char op;
        while(op = getchar(), !isdigit(op)) if(op == '-') d = - 1;
        while(isdigit(op)) f = (f << 1) + (f << 3) + (op ^ 48), op = getchar();
        return f * d;
    }
} using namespace Read;
namespace Bule13{
    const int N = 2e6 + 10;
    int n, d, ans;
    int a[N];
    int next[N], last[N];
    int cnt[N];
    int val1[N], val2[N];
    int flag[N];
    int sum1[N], sum2[N];
    inline void calc(int l, int r){
        if(l == r) return ;
        for(int i = l; i <= r; i ++ ){
            int L = i, R = r;
            while(L < R){
                int mid = (L + R + 1) >> 1;
                if(a[mid] - a[i] <= d) L = mid;
                else R = mid - 1;
            }
            next[i] = L;
            L = l, R = i;
            while(L < R){
                int mid = (L + R) >> 1;
                if(a[i] - a[mid] <= d) R = mid;
                else L = mid + 1;
            }
            last[i] = L;
            cnt[next[i]] ++ ;
        }
        for(int i = l; i <= r; i ++ ){
            if(last[i] != l){
                if(last[i] + 1 != i){
                    val1[i] = cnt[last[i] + 1];
                }
                val2[i] = cnt[last[i]];
                if(next[last[last[i]]] != last[i]){
                    if(next[last[last[i]]] == last[i] + 1){
                        flag[i] = 1;
                    }
                    else flag[i] = 2;
                }

                if(flag[i] == 0){
                    ans += val1[i] + sum1[last[i]];
                }
                else if(flag[i] == 1){
                    ans += val1[i] + sum2[last[i]];
                }
                else{
                    ans += val1[i];
                }
                // int now = i, count = 0;
                // while(last[now] != l){
                //     if(count == 0) ans += val1[now];
                //     else ans += val2[now];
                //     if(flag[now] == 2) break;
                //     if(flag[now] == 1){
                //         if(count == 1) break;
                //         count = 1;
                //     }
                //     now = last[now];
                // }

                flag[i] = val1[i] = val2[i] = 0;
                if(last[i] + 1 != i && next[last[i] + 1] == i){
                    val1[i] = cnt[last[i] + 1];
                }
                // if(next[last[i]] == i){
                    val2[i] = cnt[last[i]];
                // }
                if(next[last[last[i]]] != last[i]){
                    if(next[last[last[i]]] == last[i] + 1 && next[last[i] + 1] == i){
                        flag[i] = 1;
                    }
                    else flag[i] = 2;
                }

                if(flag[i] == 0){
                    sum1[i] = sum1[last[i]] + val1[i];
                    sum2[i] = sum2[last[i]] + val2[i];
                }
                else if(flag[i] == 1){
                    sum1[i] = sum2[last[i]] + val1[i];
                    sum2[i] = val2[i];
                }
                else{
                    sum1[i] = val1[i]; sum2[i] = val2[i];
                }
            }
        }
    }
    void sol(){
        n = read(), d = read(); ans = 0;
        for(int i = 1; i <= n; i ++ ) cnt[i] = flag[i] = val1[i] = val2[i] = sum1[i] = sum2[i] = 0;
        for(int i = 1; i <= n; i ++ ) a[i] = read();
        int la = 1;
        for(int i = 1; i <= n; i ++ ){
            if(i == n || a[i + 1] - a[i] > d){
                calc(la, i); la = i + 1;
            }
        }
        // for(int i = 1; i <= n; i ++ ) cout<<last[i]<<' '; cout<<'\n';
        // for(int i = 1; i <= n; i ++ ) cout<<next[i]<<' '; cout<<'\n';
        cout<<ans<<'\n';
    }
    signed main(){
        read(); int T = read(); while(T -- ) sol();
        return 0;
    }
}
bool ed_m;
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    Bule13::main();
    // cerr<<"time:"<<(double)clock() / CLOCKS_PER_SEC<<"\nmemory:"<<(&st_m - &ed_m) / 1024.0 / 1024.0<<'\n';
    return 0;
}
/*
g++ migrate.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\a.exe < a.in > a.out

fc migrate.out migrate6.ans

g++ migrate.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\a.exe < migrate\migrate1.in > a.out && fc a.out migrate\migrate1.ans
.\a.exe < migrate\migrate2.in > a.out && fc a.out migrate\migrate2.ans
.\a.exe < migrate\migrate3.in > a.out && fc a.out migrate\migrate3.ans
.\a.exe < migrate\migrate4.in > a.out && fc a.out migrate\migrate4.ans
.\a.exe < migrate\migrate5.in > a.out && fc a.out migrate\migrate5.ans
.\a.exe < migrate\migrate6.in > a.out && fc a.out migrate\migrate6.ans

finish:16:29

*/