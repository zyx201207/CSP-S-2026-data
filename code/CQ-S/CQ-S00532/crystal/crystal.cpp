#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<assert.h>
#include<ctime>
#define int long long
typedef long long LL;
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
    const int N = 5e5 + 10;
    int n, m, a[N], sum[N];
    signed main(){
        n = read(), m = read();
        for(int i = 1; i <= n; i ++ ) a[i] = read();
        sort(a + 1, a + 1 + n);
        int ans = 0;
        for(int i = 1; i <= n; i ++ ){
            sum[i] = sum[i - 1] + a[i];
            int l = 1, r = i;
            while(l < r){
                int mid = (l + r) >> 1;
                if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) r = mid;
                else l = mid + 1;
            }
            ans = max(ans, i - l + 1);
        }
        cout<<ans<<'\n';
        return 0;
    }
}
bool ed_m;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    Bule13::main();
    // cerr<<"time:"<<(double)clock() / CLOCKS_PER_SEC<<"\nmemory:"<<(&st_m - &ed_m) / 1024.0 / 1024.0<<'\n';
    return 0;
}
/*
g++ crystal.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000 && .\a.exe < a.in > a.out

fc crystal.out crystal.ans


g++ crystal.cpp -o a -std=c++14 -O2 -Wall -lm -Wl,--stack=2000000000
.\a.exe < crystal\crystal1.in > a.out && fc a.out crystal\crystal1.ans
.\a.exe < crystal\crystal2.in > a.out && fc a.out crystal\crystal2.ans
.\a.exe < crystal\crystal3.in > a.out && fc a.out crystal\crystal3.ans
.\a.exe < crystal\crystal4.in > a.out && fc a.out crystal\crystal4.ans

finish:14:34

*/