#include<bits/stdc++.h>
#define MAXN 500200
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
unsigned long long m;
int n , ans = 0;
ll a[MAXN] = {0};
void solve1(){
    sort(a + 1 , a + n + 1);
    for(int i = n ;i > ans ;i--){
        ull sum = 0;
        int cnt = 1;
        while(1){
            sum += a[i] - a[i - cnt];
            if(sum <= m) cnt++;
            else break;
        }
        ans = max(ans , cnt);
    }
    cout << ans;
}
void solve2(ull cha){
    for(int i = 2;i <= n;i++)
        if(cha * (i + 1) * i / 2 > m) {cout << i; return ;}
    cout << n;
}
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.ans" , "w" , stdout);
    ios :: sync_with_stdio(0);
    cin .tie(0);
    cin >> n >> m;
    if(n == 1) {cout << 1; return 0;}
    cin >> a[1] >> a[2];
    ll cha = a[2] - a[1];
    bool chad = true;
    for(int i = 3;i <= n;i++){
        cin >> a[i];
        if(cha != a[i] - a[i - 1]) chad = false;
    }
    if(chad) solve2(cha);
    else solve1();
    return 0;
}
