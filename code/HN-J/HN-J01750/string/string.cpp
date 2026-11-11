#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;

int n, a[N];
ll len;
char in[N];

namespace subtask1{
    string s, t1, t2;
    int ans;

    void init(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= a[i]; j++){
                s += in[i];
            }
        }
        int l = s.size();
        for(int i = 0; i < l; i++){
            if(i < l / 2){
                t1 += s[i];
            }
            if((l % 2 && i > l / 2) || (!(l % 2) && i >= l / 2)){
                t2 += s[i];
            }
        }
    }

    void solve(){
        init();
        ans = 0;
        reverse(t2.begin(), t2.end());
        for(int i = 0; i < t1.size(); i++){
            ans += (t1[i] != t2[i]);
        }
        cout << ans;
    }
}

namespace subtask2{
    ll now, ans;

    void solve(){
        now = ans = 0;
        int op = len % 2;
        for(int i = 1, j = n; i != j;){
            if(a[i] == 0) i++;
            if(a[j] == 0) j++;
            if(a[i] < a[j]){
                a[j] -= a[i];
                ans += (in[i] != in[j]) * a[i];
                now += a[i];
                i++;
                continue;
            } else{
                a[i] -= a[j];
                ans += (in[i] != in[j]) * a[j];
                now += a[j];
                j--;
                continue;
            }
        }
        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> in[i];
        len += a[i];
    }
    if(len <= 2e7){
        subtask1::solve();
    } else{
        subtask2::solve();
    }
    return 0;
}
