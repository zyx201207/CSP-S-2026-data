#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 9;

ll n, sum = 0, x[N], pre[N], L;
string s = " ";
char a[N];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int wwww = 1;
    pre[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> a[i];
        pre[i] = pre[i - 1] + x[i];
        if(x[i] >= 1000){
            wwww = 0;
        }
        L += x[i];
    }
    if(n <= 10 && wwww){
        int ssss = 0;
        string ll = " ";
        int pp = 0, sss = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= x[i]; j++){
                ll += a[i];
            }
            pp += x[i];
        }
        for(int i = 1; i <= pp; i++){
            if(ll[i] != ll[pp + 1 - i]){
                ssss++;
            }
        }
        cout << ssss / 2;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        ll l = pre[i - 1], r = pre[i] - 1;
        char w = a[i];
        auto q = lower_bound(pre + 1, pre + n + 1, L + 1 - r) - pre;
        auto p = upper_bound(pre + 1, pre + n + 1, L + 1 - l) - pre;
        //cout << L + 1 - r << " " << pre[q] << '\n';
        //cout << 11111 << " " << q << " " << p << '\n';
        for(int j = q; j <= p; j++){
            if(w != a[j]){
                if(j == q){
                    sum += max(L + 1 - r - pre[q - 1], 1ll);
                } else if(j == p){
                    sum += max(L + 1 - l - pre[p - 1], 1ll);
                } else{
                    sum += x[j];
                }
            }
        }
    }
    cout << sum / 2;
    return 0;
}
