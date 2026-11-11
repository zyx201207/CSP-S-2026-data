#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
#define ll long long
int n;
char c[N];
ll a[N], ans;
#define pii pair<char, ll>
vector<pii>b, c2;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ll cnt = 0;
    for (int i = 1; i <= n; i+=1){
        cin >> a[i] >> c[i];
        cnt += a[i];
    }
    cnt /= 2;
    ll s = 0;
    for (int i = 1; i <= n; i+=1){
        if (s + a[i] <= cnt){
            s += a[i];
            b.push_back({c[i], a[i]});
        }
        else{
            a[i] -= cnt-s;
            b.push_back({c[i], cnt-s});
            break;
        }
    }
    s = 0;
    for (int i = n; i >= 1; i-=1){
        if (s + a[i] <= cnt){
            s += a[i];
            c2.push_back({c[i], a[i]});
        }
        else{
            a[i] -= cnt-s;
            c2.push_back({c[i], cnt-s});
            break;
        }
    }
    ll l, r;
    l = r = 0;
    while(true){
        if (b[l].first == c2[r].first){
            if (b[l].second > c2[r].second){
                b[l].second -= c2[r].second;
                r++;
            }
            else{
                c2[r].second -= b[l].second;
                if (c2[r].second == 0) r++;
                l++;
            }
        }
        else{
            if (b[l].second > c2[r].second){
                ans += c2[r].second;
                b[l].second -= c2[r].second;
                r++;
            }
            else{
                ans += b[l].second;
                c2[r].second -= b[l].second;
                if (c2[r].second == 0) r++;
                l++;
            }
        }
        if (l >= b.size() || r >= c2.size()) break;
    }
    cout << ans;
    return 0;
}
