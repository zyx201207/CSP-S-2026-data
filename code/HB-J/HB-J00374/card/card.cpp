#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, maxn = 0;
    cin >> n >> m;
    vector<ll> p(n);
    vector<ll> end(m + 5, 0);
    for(ll i = 1; i <= n; i ++){
        cin >> p[i];
        maxn = max(maxn, p[i]);
    }
    if(m == 1){
        cout << n << '\n';
        return 0;
    }
    else if(maxn == 2) {
        for(ll i = 1; i <= n; i ++){
            end[p[n]] ++;
            if(p[i] != p[n]) end[(p[n] == 1 ? 2 : 1)] ++; 
        }
        cout << end[1] << ' ' << end[2] << '\n';
        return 0;
    }
    for(ll i = 1; i <= n; i ++) {
        deque<ll> dq, ans;
        vector<bool> inque(m + 5, false);
        for(ll j = i; j <= n; j ++) dq.push_back(p[j]);
        while (!dq.empty()) {
            ll x = dq.front();
            dq.pop_front();
            if(!inque[x]){
                inque[x] = true;
                ans.push_back(x);
            }
            else {
                while (ans.back() != x && !ans.empty()) {
                    ll y = ans.back();
                    ans.pop_back();
                    inque[y] = false;
                }
            }
        }
        while (!ans.empty()) {
            end[ans.front()] ++;
            ans.pop_front();
        }
    }
    for(ll i = 1; i <= m; i ++) cout << end[i] << " \n"[i == m];
    return 0;
}