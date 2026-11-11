#include<bits/stdc++.h>
#define ll long long
int s, maxx, sum;
ll a[100005];
bool vis[100005];
void dfs(ll x, ll n, ll m){
    if(x == n){
        for(int i = 1; i <= n;  i ++){
            if(vis[i] == 1){
                s ++;
            }
        }
        if(s == m){
            for(int i = 1; i <= n; i ++){
                if(vis[i] = 1){
                    sum = (sum & a[i]);
                }
            }
            if(sum > maxx)maxx = sum;
            return;
        }
    }
    vis[x] = 0;
    dfs(x + 1, n,  m);
    vis[x] = 1;
    dfs(x + 1, n, m);
}
using namespace std;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out","w",stdout);
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++)cin >> a[i];
    dfs(1, n, m);
    cout << maxx;
    return 0;
}
