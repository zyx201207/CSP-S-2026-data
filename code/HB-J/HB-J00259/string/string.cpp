#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
ll a[maxn], n, len = 0;
char s[maxn];
map<ll, char> mp;
char find(ll x){
    ll y = mp[x];
    if(y) return y;
    ll sum = 0;
    for(int i = 1;i <= n;i++){
        if(sum + a[i] >= x) return mp[x] = s[i];
        else sum += a[i];
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int i, j;ll ans = 0;
    cin >> n;
    for(i = 1;i <= n;i++){
        cin >> a[i] >> s[i];
        len += a[i];
    }
    if(len <= 1e7){
        ans = len / 2;
        for(i = 1, j = len;i < j;i++, j--)
            if(find(i) == find(j))
                ans--;
    }else{
        ll ls = 0, rs = 0; ans = 0;
        char now = 0;int f = -10000;
        for(i = 1, j = n;i < j;i++, j--){
            if(f && now != s[i]){
                if(a[i] < rs){
                        rs -= a[i], ans += a[i], i--;
                        //cout << i << ' ' << j  << ' ' << ls << ' ' << rs << ' ' << ans << ' ' << (char)now << ' ' << f << endl;
                        continue;
                }
                else ans += rs, a[i] -= rs;
            }
            if(!f && now != s[j]){
                if(a[i] < ls){
                        ls -= a[j], ans += a[j], j++;
                        //cout << i << ' ' << j  << ' ' << ls << ' ' << rs << ' ' << ans << ' ' << (char)now << ' ' << f << endl;
                        continue;
                }
                else ans += ls, a[i] -= ls;
            }
            if(s[i] != s[j]){
                ans += min(a[i], a[j]);
                if(a[i] == a[j]) f = -1, ls = 0, rs = 0;
                else if(a[i] < a[j]) rs = a[j] - a[i], now = s[j], f = 1;
                else ls = a[i] - a[j], now = s[i], f = 0;
            }
            //cout << i << ' ' << j  << ' ' << ls << ' ' << rs << ' ' << ans << ' ' << (char)now << ' ' << f << endl;
        }
    }
    cout << ans;
    return 0;
}
