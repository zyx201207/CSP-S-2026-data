#include<ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
bool ST; namespace furina{
    const int N = 5e5, inf = 0x7fffffff >> 1;

    int n;
    ll m;
    int a[N + 10];

    int main(){
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);

        int ans = 1;
        ll cost = 0;
        for(int r = 1, l = 1, cur = a[1]; r <= n; r++){
            cost += (r - l) * (a[r] - cur);
            while(cost > m)
                cost -= a[r] - a[l++];
            ans = max(ans, r - l + 1);
            cur = a[r];
        }

        cout << ans << '\n';
        return 0;
    }
} bool ED;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    furina::main();
    cerr << (1000. * clock() / CLOCKS_PER_SEC) << "ms" << '\n';
    cerr << (abs(&ST - &ED) >> 20) << "mb" << '\n';
    return 0;
}
/*
g++ -o crystal crystal.cpp -std=c++14 -Wall -O2 -lm -Wl,--stack=2000000000 & .\crystal
*/