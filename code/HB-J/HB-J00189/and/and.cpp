#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, m;
#define ll long long
ll ans, p[31];
int v[N], ls, s[31];
struct stu{
    ll w;
    short k[31];
};
stu a[N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i < 30; i += 1){
        p[i] = p[i-1]*2;
    }
    for (int i = 1; i <= n; i += 1) {
        v[i] = 1;
        cin >> a[i].w;
        for (int j = 0; j < 30; j += 1){
            a[i].k[j] = ((a[i].w&p[j])>0);
            s[j] += a[i].k[j];
        }
    }
    for (int i = 29; i >= 0; i -= 1){
        if (s[i] >= m){
            ans += p[i];
            for (int j = 1; j <= n; j += 1){
                if (!v[j]) continue;
                if (a[j].k[i] == 0){
                    v[j] = 0;
                    for (int jj = 0; jj < 30; jj += 1){
                        s[jj] -= a[j].k[jj];
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
