#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

const int MAXN = 5e5 + 5;
ll n, m, a[MAXN];

//g++ 1.cpp -o 1 -std=c++14 -O2 -Wall -Wextra -Wfloat-equal -Wshadow

//i want to play genshin impact

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }

    sort(a + 1, a + n + 1);

    ll cur = 0, res = 1, p = 1, ans = 0;

    for(int i = 1; i <= n; i++){
        if(i != 1){
            cur += (a[i] - a[i-1]) * (i - p);
            res++;
        }
        while(cur > m){
            cur -= a[i] - a[p];
            res--;
            p++;
        }
        ans = max(ans, res);
    }

    cout<<ans<<'\n';

    return 0;
}