#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 10;
struct node{
    ll sl;
    char zf;
}w[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> w[i].sl >> w[i].zf;
    }
    ll clt = 0;
    for(ll i = 1; i <= n; i++){
        clt += w[i].sl;
        for(ll j = 1; j <= w[i].sl; j++){
            s += w[i].zf;
        }
    }
    string st = s;
    reverse(s.begin(), s.end());
    if(st == s){
        cout << 0;
        return 0;
    }
    ll l = 0, r = clt;
    ll cnt = 0;
    while(l <= r){
        if(s[l] != s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout << cnt;
    return 0;
}
