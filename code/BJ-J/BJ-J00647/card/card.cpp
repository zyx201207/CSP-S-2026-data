#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[500005];
ll ans[500005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        stack<ll> p;
        while(!p.empty()) {
            p.pop();
        }
        for(int j = i;j <= n;j++) {
            if(p.empty()) {
                p.push(a[j]);
                continue;
            }
            stack<ll> k = p;
            ll siz = k.size();
            ll is = 0;
            for(int i = 1;i <= siz;i++) {
                ll now = k.top();
                k.pop();
                if(now == a[j]) {
                    k.push(a[j]);
                    is = 1;
                    break;
                }
            }
            if(is == 1) {
                p = k;
                continue;
            }
            p.push(a[j]);
        }
        while(!p.empty()) {
            ll now = p.top();
            //cout << "now = " << now << endl;
            p.pop();
            ans[now]++;
        }
        //cout << endl;
    }
    for(ll i = 1;i <= m;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
