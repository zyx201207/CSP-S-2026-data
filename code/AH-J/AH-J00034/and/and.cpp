#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
using ll = long long;
int n, m;
vector<ll> a;
ll ans = 0;
int find_max(){
    ll maxn = a[0];
    int tar = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] > maxn){
            maxn = a[i];
            tar = i;
        }
    }
    return tar;
}
int main(){
    freopen("and3.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    int ti = find_max();
    ans = a[ti];
    a[ti] = -1;
    for(int i = 1; i < m; i++){
        int idx = find_max();
        cout << ans << endl;
        cout << "max:" << a[idx] << endl;
        ans = ans & a[idx];
        a[idx] = -1;
    }
    cout << ans << endl;
    return 0;
}
