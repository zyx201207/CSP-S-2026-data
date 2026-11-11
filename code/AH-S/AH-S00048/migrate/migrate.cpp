#include <bits/stdc++.h>
using namespace std;

//Oct31==Dec25?
typedef long long ll;
const int N = 2e6+10;
ll c, _;
ll n, d;
ll a[N];
struct node{
    ll u, w;
};
vector <node> g[3005];
ll dp[N], s[N];
int main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> c >> _;
    while(_--){
        memset(dp, 0x3f, sizeof(dp));
        memset(s, 0, sizeof(s));
        cin >> n >> d;
        for(int i = 1;i <= n;i++)   g[i].clear();
        for(int i = 1;i <= n;i++)   cin >> a[i];
        bool flag = true;
        for(int i = 3;i <= n;i++)   if(a[i]-a[i-1] != a[i-1]-a[i-2])    flag = false;
        if(n < 3){cout << 0 << '\n';continue;}
        if(flag){
            if(d < a[2]-a[1]){cout << 0 << '\n';continue;}
            ll w = d/(a[2]-a[1]);
            ll res = w+w-1;
            cout << max(n-res, (ll)0) << '\n';
            continue;
        }
        int l = 1, r = 2;
        for(;l <= r;){
            if(a[r]-a[l] <= d){
                for(int i = l;i < r;i++)
                    g[i].push_back({r, 1});
                if(r < n) r++;
                else break;
            }
            else    l++;
        }
        dp[1] = 0, s[1] = 1;
        for(int i = 1;i <= n;i++){
            for(auto v : g[i]){
                if(v.w+dp[i] < dp[v.u])
                    dp[v.u] = v.w+dp[i], s[v.u] = 1;
                else if(v.w+dp[i] == dp[v.u])
                    s[v.u] += s[i];
            }
        }
        ll ans = 0;/*
        for(int i = 1;i <= n;i++){
            cout << s[i] << ' ';
        }cout << endl;
        for(int i = 1;i <= n;i++){
            cout << dp[i] << ' ';
        }cout << endl;*/
        for(int i = 1;i <= n;i++)   if(s[i] == 2)   ans++;
        cout << ans << '\n';
    }
    return 0;
}
