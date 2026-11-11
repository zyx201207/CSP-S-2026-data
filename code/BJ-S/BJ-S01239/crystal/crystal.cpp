#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m, a[N], cha[N];
/*
x x xxx 音乐水晶(Xterfusion)
*/
int getans(ll val) {
    int cnt = 0, id;
    ll t = m, minc = 1e18;
    for(int i = 1; i <= n; i++) cha[i] = val - a[i];
    for(int i = 1; i <= n; i++) {
        if(abs(cha[i]) <= minc) {
            minc = abs(cha[i]);
            id = i;
        } else break;
    }
    for(int i = 1; i <= id; i++) {
        if(t < 0) break;
        t -= cha[i];
        cnt++;
    }
    return cnt;

}
void solve1() {
    int maxn = -1;
    for(int i = 1; i <= n; i++) maxn = max(maxn, getans(a[i]));
    cout << maxn ;
    return;
}
void solve2() {
    int pos = n / 2 + 1;
    cout << getans(a[pos]) ;
    return;
}
void solve3() {
    int maxn = -1;
    for(int i = -100; i <= 100; i++) maxn = max(maxn, getans(i));
    cout << maxn ;
    return;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m ;
    for(int i = 1; i <= n; i++) cin >> a[i] ;
    sort(a + 1, a + n + 1);
    if(n <= 5000) solve1();
    else if(a[1] >= -100 && a[n] <= 100) solve3();
    else solve2();
    return 0;
}
/*
UID:1318015 Linda0417
咕
如果有人看过2025年BJ的迷惑行为大赏的话，里面那个说自己只有十分（实际爆零）、画了一个字符画的就是我
今年我要求不高，只要拿二等奖就够了
如果我不拿奖的话我可能会退役，所以这可能是我最后一次CSP。我想再上一次迷惑行为大赏（虽然我也不知道为什么）
祝看到这里的所有人都能拿到自己满意的成绩！
*/
